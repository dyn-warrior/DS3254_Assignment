#include <iostream>
#include <vector>

class Matrix {
private:
    std::vector<std::vector<int>> mat;
    int rows, cols;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        mat.resize(rows, std::vector<int>(cols, 0));
    }

    // Function to input matrix elements
    void inputMatrix() {
        std::cout << "Enter matrix elements (" << rows << "x" << cols << "):\n";
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cin >> mat[i][j];
            }
        }
    }

    // Function to print the matrix
    void print() const {
        for (const auto& row : mat) {
            for (int val : row) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
    }

    // Matrix addition
    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols) {
            throw std::invalid_argument("Matrix dimensions must match for addition.");
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[i][j] = mat[i][j] + other.mat[i][j];
            }
        }
        return result;
    }

    // Matrix multiplication
    Matrix operator*(const Matrix& other) {
        if (cols != other.rows) {
            throw std::invalid_argument("Invalid matrix dimensions for multiplication.");
        }
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    // Transpose matrix
    Matrix transpose() {
        Matrix result(cols, rows);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.mat[j][i] = mat[i][j];
            }
        }
        return result;
    }
};

// Driver code
int main() {
    int r1, c1, r2, c2;
    
    // Input first matrix
    std::cout << "Enter dimensions of first matrix (rows cols): ";
    std::cin >> r1 >> c1;
    Matrix mat1(r1, c1);
    mat1.inputMatrix();

    // Input second matrix
    std::cout << "Enter dimensions of second matrix (rows cols): ";
    std::cin >> r2 >> c2;
    Matrix mat2(r2, c2);
    mat2.inputMatrix();

    // Display matrices
    std::cout << "Matrix 1:\n";
    mat1.print();
    std::cout << "Matrix 2:\n";
    mat2.print();

    // Matrix addition
    if (r1 == r2 && c1 == c2) {
        Matrix sum = mat1 + mat2;
        std::cout << "Sum:\n";
        sum.print();
    } else {
        std::cout << "Addition not possible (different dimensions).\n";
    }

    // Matrix multiplication
    if (c1 == r2) {
        Matrix product = mat1 * mat2;
        std::cout << "Product:\n";
        product.print();
    } else {
        std::cout << "Multiplication not possible (column count of first must match row count of second).\n";
    }

    // Transpose of first matrix
    std::cout << "Transpose of Matrix 1:\n";
    Matrix t1 = mat1.transpose();
    t1.print();

    return 0;
}
