//2. Sparse Matrix Using Vector of Pairs
#include <iostream>
#include <vector>

class SparseMatrix {
private:
    int rows, cols;
    std::vector<std::pair<std::pair<int, int>, int>> data; // { {row, col}, value }

public:
    // Constructor
    SparseMatrix(int r, int c) : rows(r), cols(c) {}

    // Insert non-zero value
    void insert(int i, int j, int value) {
        if (value != 0) {
            data.push_back({{i, j}, value});
        }
    }

    // Get value at (i, j)
    int get(int i, int j) const {
        for (const auto &entry : data) {
            if (entry.first.first == i && entry.first.second == j)
                return entry.second;
        }
        return 0;
    }

    // Display matrix
    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << get(i, j) << " ";
            }
            std::cout << "\n";
        }
    }

    // Sparse Matrix Addition
    SparseMatrix add(const SparseMatrix &other) {
        if (rows != other.rows || cols != other.cols) {
            throw std::runtime_error("Matrix dimensions must match for addition.");
        }
        SparseMatrix result(rows, cols);
        for (const auto &entry : data) {
            result.insert(entry.first.first, entry.first.second, entry.second);
        }
        for (const auto &entry : other.data) {
            int existingValue = result.get(entry.first.first, entry.first.second);
            result.insert(entry.first.first, entry.first.second, existingValue + entry.second);
        }
        return result;
    }
};

// Driver Code
int main() {
    SparseMatrix mat(4, 4);
    mat.insert(0, 1, 5);
    mat.insert(1, 2, 10);
    mat.insert(2, 3, 15);

    std::cout << "Sparse Matrix:\n";
    mat.display();

    SparseMatrix mat2(4, 4);
    mat2.insert(0, 1, 3);
    mat2.insert(1, 2, 2);
    mat2.insert(2, 3, 4);

    SparseMatrix result = mat.add(mat2);
    std::cout << "Sparse Matrix Addition Result:\n";
    result.display();

    return 0;
}
