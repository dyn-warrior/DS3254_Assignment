//C++ Implementation of Full Sequence ADT using Linked List

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

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Prepend (Insert at beginning)
    void prepend(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Append (Insert at end)
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a specific position (0-based index)
    void insertAt(int value, int position) {
        if (position == 0) {
            prepend(value);
            return;
        }
        Node* newNode = new Node(value);
        Node* temp = head;
        for (int i = 0; i < position - 1 && temp; i++) {
            temp = temp->next;
        }
        if (!temp) {
            std::cout << "Position out of bounds!\n";
            return;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete at a specific position (0-based index)
    void deleteAt(int position) {
        if (!head) return;
        Node* temp = head;

        if (position == 0) {
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = nullptr;
        for (int i = 0; i < position && temp; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            std::cout << "Position out of bounds!\n";
            return;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Search for an element, returns index or -1 if not found
    int search(int value) {
        Node* temp = head;
        int index = 0;
        while (temp) {
            if (temp->data == value) return index;
            temp = temp->next;
            index++;
        }
        return -1;
    }

    // Get element at an index
    int get(int index) {
        Node* temp = head;
        for (int i = 0; i < index && temp; i++) {
            temp = temp->next;
        }
        if (!temp) {
            std::cout << "Index out of bounds!\n";
            return -1;
        }
        return temp->data;
    }

    // Update element at an index
    void update(int index, int newValue) {
        Node* temp = head;
        for (int i = 0; i < index && temp; i++) {
            temp = temp->next;
        }
        if (!temp) {
            std::cout << "Index out of bounds!\n";
            return;
        }
        temp->data = newValue;
    }

    // Print the linked list
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

// Driver Code
int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);
    std::cout << "List after append operations: ";
    list.print();

    list.prepend(5);
    std::cout << "List after prepending 5: ";
    list.print();

    list.insertAt(15, 2);
    std::cout << "List after inserting 15 at index 2: ";
    list.print();

    list.deleteAt(3);
    std::cout << "List after deleting element at index 3: ";
    list.print();

    int value = 20;
    int index = list.search(value);
    if (index != -1)
        std::cout << value << " found at index " << index << "\n";
    else
        std::cout << value << " not found\n";

    int getIndex = 2;
    std::cout << "Element at index " << getIndex << ": " << list.get(getIndex) << "\n";

    list.update(1, 25);
    std::cout << "List after updating index 1 to 25: ";
    list.print();

    return 0;
}
