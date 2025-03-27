//Implementation of Binary Tree with Traversal

#include <iostream>

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    TreeNode* root;

    BinaryTree() {
        root = nullptr;
    }

    // Preorder Traversal (Root -> Left -> Right)
    void preorder(TreeNode* node) {
        if (node == nullptr) return;
        std::cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Inorder Traversal (Left -> Root -> Right)
    void inorder(TreeNode* node) {
        if (node == nullptr) return;
        inorder(node->left);
        std::cout << node->data << " ";
        inorder(node->right);
    }

    // Postorder Traversal (Left -> Right -> Root)
    void postorder(TreeNode* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        std::cout << node->data << " ";
    }

    // Wrapper functions to call traversals from main
    void preorder() { preorder(root); }
    void inorder() { inorder(root); }
    void postorder() { postorder(root); }
};

// Driver Code
int main() {
    BinaryTree tree;
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);
    tree.root->right->left = new TreeNode(6);
    tree.root->right->right = new TreeNode(7);

    std::cout << "Preorder Traversal: ";
    tree.preorder();
    std::cout << "\n";

    std::cout << "Inorder Traversal: ";
    tree.inorder();
    std::cout << "\n";

    std::cout << "Postorder Traversal: ";
    tree.postorder();
    std::cout << "\n";

    return 0;
}
