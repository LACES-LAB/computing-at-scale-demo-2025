#ifndef LINEAR_ALGEBRA_H
#define LINEAR_ALGEBRA_H

#include <vector>
#include <string>

using Matrix = std::vector<std::vector<double>>;
using Vector = std::vector<double>;

// Function that computes the product of a dense matrix with a vector.
Vector matrixVectorProduct(const Matrix& matrix, const Vector& vector);

// Function that computes the product of two dense matrices.
Matrix matrixMatrixProduct(const Matrix& matrix0, const Matrix& matrix1);

// Function to load a matrix from a file in Matrix Market format
Matrix loadMatrix(const std::string& filename);

// Funtion to print in a matrix format
void printMatrix(const Matrix& matrix);

#endif