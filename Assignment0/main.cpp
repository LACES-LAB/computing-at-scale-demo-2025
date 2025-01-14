#include "linear_algebra.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc !=4) {
        std::cerr << "Usage" << argv[0] << " <filename1> <filename2> <type 0 or 1>\n";
    }

    std::string filename1 = argv[1];
    std::string filename2 = argv[2];
    int type = std::stoi(argv[3]);

    try {
        if (type == 0) {
            Matrix matrix = loadMatrix(filename1);
            Vector vector = loadMatrix(filename2)[0];
            Vector results = matrixVectorProduct(matrix, vector);
            for (const auto& value : results) std::cout << value << "\n";
        }
        else if (type == 1) {
            Matrix matrix0 = loadMatrix(filename1);
            Matrix matrix1  = loadMatrix(filename2);
            Matrix results = matrixMatrixProduct(matrix0, matrix1);
            printMatrix(results);
        }
        else {
            std::cerr << "invalid type.\n";
            return 1;
        }
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}