#include <iostream>

class myArray {
private:
    int* arr;
    int capacity;
    int size;

public:
    // Constructor
    myArray(int cap = 10) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    // Destructor
    ~myArray() {
        delete[] arr;
    }

    // Insert an element at a specific index
    void insert(int index, int value) {
        if (index < 0 || index > size) {
            std::cout << "Invalid index!\n";
            return;
        }
        
        // Resize if full
        if (size == capacity) {
            resize();
        }

        // Shift elements to the right
        for (int i = size; i > index; i--) {
            arr[i] = arr[i - 1];
        }

        // Insert element
        arr[index] = value;
        size++;
    }

    // Remove an element at a specific index
    void remove(int index) {
        if (index < 0 || index >= size) {
            std::cout << "Invalid index!\n";
            return;
        }

        // Shift elements to the left
        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // Resize array when full
    void resize() {
        capacity *= 2;
        int* newArr = new int[capacity];
        
        for (int i = 0; i < size; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }

    // Print array
    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }
};

// Driver Code
int main() {
    myArray arr(5);

    arr.insert(0, 10);
    arr.insert(1, 20);
    arr.insert(2, 30);
    arr.insert(3, 40);
    arr.insert(4, 50);

    std::cout << "Array after insertions: ";
    arr.print();

    arr.remove(2); // Remove element at index 2

    std::cout << "Array after removal: ";
    arr.print();

    return 0;
}
