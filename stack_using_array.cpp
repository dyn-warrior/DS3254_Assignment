//1. Stack ADT using Array/Vector

#include <iostream>
#include <vector>

class Stack {
private:
    std::vector<int> arr;

public:
    // Push element onto stack
    void push(int value) {
        arr.push_back(value);
    }

    // Pop element from stack
    void pop() {
        if (arr.empty()) {
            std::cout << "Stack Underflow\n";
            return;
        }
        arr.pop_back();
    }

    // Peek top element
    int peek() {
        if (arr.empty()) {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        return arr.back();
    }

    // Check if stack is empty
    bool isEmpty() {
        return arr.empty();
    }

    // Print stack elements
    void print() {
        for (int i = arr.size() - 1; i >= 0; i--)
            std::cout << arr[i] << " ";
        std::cout << "\n";
    }
};

// Driver Code
int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    std::cout << "Stack elements: ";
    s.print();
    std::cout << "Top element: " << s.peek() << "\n";
    s.pop();
    std::cout << "Stack after pop: ";
    s.print();
    return 0;
}
