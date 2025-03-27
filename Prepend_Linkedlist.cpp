//C++ Implementation of Linked List with prepend
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = nullptr;
    }

    // Prepend (Insert at the beginning)
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head; // Point new node to the old head
        head = newNode;       // Update head to new node
    }

    // Print the list
    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL\n";
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver code
int main() {
    LinkedList list;

    list.prepend(10);
    list.prepend(20);
    list.prepend(30);

    std::cout << "Linked List after prepending elements: ";
    list.print();

    return 0;
}
