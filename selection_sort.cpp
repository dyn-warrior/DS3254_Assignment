//1. Selection Sort Implementation
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

// Function to perform Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Function to read input from the keyboard
vector<int> readFromKeyboard() {
    cout << "Enter numbers separated by spaces: ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

// Function to read input from a file
vector<int> readFromFile(const string& filename) {
    ifstream file(filename);
    vector<int> arr;
    if (!file) {
        cerr << "Error: File not found!" << endl;
        exit(1);
    }
    int num;
    while (file >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main(int argc, char* argv[]) {
    vector<int> numbers;

    if (argc > 1) {
        // Read from file if a filename is provided as a command-line argument
        numbers = readFromFile(argv[1]);
    } else {
        // Read from keyboard if no filename is provided
        numbers = readFromKeyboard();
    }

    cout << "Original array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    selectionSort(numbers);

    cout << "Sorted array: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
