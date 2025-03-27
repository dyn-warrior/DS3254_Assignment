//2. Stack ADT using Linked List
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    // Push element onto stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Pop element from stack
    void pop() {
        if (!top) {
            std::cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    // Peek top element
    int peek() {
        if (!top) {
            std::cout << "Stack is Empty\n";
            return -1;
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Print stack elements
    void print() {
        Node* temp = top;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << "\n";
    }

    // Destructor to free memory
    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
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
