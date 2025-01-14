#include "linear_algebra.h"
#include <iostream>
#include <fstream>
#include <sstream>

Vector matrixVectorProduct(const Matrix& matrix, const Vector& vector) {
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    if (vector.size() != cols) {
        throw std::invalid_argument("Matrix and vector size mismatch and cannot prodcut.");
    }
    Vector results(rows, 0.0);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            results[i] += matrix[i][j] * vector[j];
    return results;
}

Matrix matrixMatrixProduct(const Matrix& matrix0, const Matrix& matrix1) {
    size_t rows_0 = matrix0.size();
    size_t cols_0 = matrix0[0].size();
    size_t rows_1 = matrix1.size();
    size_t cols_1 = matrix1[0].size();
    if (cols_0 != rows_1) {
        throw std::invalid_argument("Matrix size mismatch and cannot product.");
    }
    Matrix results(rows_0, Vector(cols_1, 0.0));
    for (size_t i = 0; i < rows_0; ++i)
        for (size_t j = 0; j < cols_1; ++j)
            for (size_t k = 0; k < cols_0; ++k)
                results[i][j] += matrix0[i][k] * matrix1[k][j];
    return results;
}

Matrix loadMatrix(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("file not exists.");
    }
    std::string line;
    // Skip header lines starting with '%'
    while (std::getline(file, line)) {
        if (line[0] != '%') break;
    }
    // Read matrix dimensions
    std::istringstream lines(line);
    size_t rows, cols;
    lines >> rows >> cols;
    // Initialize a dense matrix with zeros
    std::vector<std::vector<double>> matrix(rows, std::vector<double>(cols, 0.0));
    size_t rowIndex = 0, colIndex = 0;
    double value = 0.0;
    while (std::getline(file, line)) {
        std::istringstream dataLine(line);
        dataLine >> rowIndex >> colIndex >> value;
        matrix[rowIndex - 1][colIndex - 1] = value;
    }
    file.close();
    return matrix;
}

// void printMatrix(const Matrix& matrix) {
//     std::cout<<"%%MatrixMarket matrix array real general\n";
//     std::cout<< matrix.size() << "" << matrix[0].size() << matrix.size() * matrix[0].size() <<"\n";
//     for (const auto& row : matrix)
//         for (const auto& value : row)
//             std::cout << value << "\n";
// }

void printMatrix(const Matrix& matrix) {
    std::cout << "%%MatrixMarket matrix coordinate real general\n";
    std::cout << matrix.size() << " " << matrix[0].size() << " " << matrix.size() * matrix[0].size() << "\n";
    
    for (size_t i = 0; i < matrix.size(); ++i) {
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            std::cout << i + 1 << " " << j + 1 << " " << matrix[i][j] << "\n";
        }
    }
}

