//1. Matrix Class Using 1-D Array Representation

#include <iostream>
#include <iomanip>

class Matrix1D {
private:
    int rows, cols;
    int *data; // 1D array for matrix storage

public:
    // Constructor
    Matrix1D(int r, int c) : rows(r), cols(c) {
        data = new int[rows * cols]();
    }

    // Destructor
    ~Matrix1D() {
        delete[] data;
    }

    // Set value at (i, j)
    void set(int i, int j, int value) {
        data[i * cols + j] = value;
    }

    // Get value at (i, j)
    int get(int i, int j) const {
        return data[i * cols + j];
    }

    // Display Matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << std::setw(4) << get(i, j) << " ";
            }
            std::cout << "\n";
        }
    }

    // Matrix Addition
    Matrix1D add(const Matrix1D &other) {
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Matrix dimensions must match for addition.");
        }
        Matrix1D result(rows, cols);
        for (int i = 0; i < rows * cols; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }
};

// Driver Code
int main() {
    Matrix1D mat(3, 3);
    mat.set(0, 0, 1);
    mat.set(1, 1, 2);
    mat.set(2, 2, 3);

    std::cout << "Matrix:\n";
    mat.display();

    Matrix1D mat2(3, 3);
    mat2.set(0, 0, 4);
    mat2.set(1, 1, 5);
    mat2.set(2, 2, 6);

    Matrix1D result = mat.add(mat2);
    std::cout << "Matrix Addition Result:\n";
    result.display();

    return 0;
}
