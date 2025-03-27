//Binary Search Tree (BST) Implementation in C++
#include <iostream>

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper function to insert a node
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    // Helper function to search for a node
    bool search(Node* node, int value) {
        if (!node) return false;
        if (value == node->data) return true;
        if (value < node->data) return search(node->left, value);
        return search(node->right, value);
    }

    // Helper function to find the minimum value node
    Node* findMin(Node* node) {
        while (node->left) node = node->left;
        return node;
    }

    // Helper function to delete a node
    Node* remove(Node* node, int value) {
        if (!node) return node;
        if (value < node->data)
            node->left = remove(node->left, value);
        else if (value > node->data)
            node->right = remove(node->right, value);
        else {
            // Node with one child or no child
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children, get inorder successor
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = remove(node->right, temp->data);
        }
        return node;
    }

    // Inorder Traversal (Left, Root, Right)
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

public:
    BST() : root(nullptr) {}

    // Insert function
    void insert(int value) {
        root = insert(root, value);
    }

    // Search function
    bool search(int value) {
        return search(root, value);
    }

    // Remove function
    void remove(int value) {
        root = remove(root, value);
    }

    // Display BST in sorted order
    void display() {
        inorder(root);
        std::cout << "\n";
    }
};

// Driver Code
int main() {
    BST bst;
    
    // Inserting values
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    std::cout << "Inorder Traversal: ";
    bst.display();

    // Searching elements
    std::cout << "Search 40: " << (bst.search(40) ? "Found" : "Not Found") << "\n";
    std::cout << "Search 25: " << (bst.search(25) ? "Found" : "Not Found") << "\n";

    // Deleting a node
    bst.remove(50);
    std::cout << "After deleting 50: ";
    bst.display();

    return 0;
}

