//Implement a constructor for Binary Tree class that takes pre-order and in-order sequences as input.
#include <iostream>
#include <vector>
#include <unordered_map>

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
private:
    std::unordered_map<int, int> inorderMap; // Map to store inorder indices
    int preIndex = 0; // Keeps track of the current index in preorder array

    // Recursive function to build the tree
    TreeNode* buildTreeHelper(const std::vector<int>& preorder, const std::vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) return nullptr;

        int rootValue = preorder[preIndex++]; // Pick current root from preorder
        TreeNode* root = new TreeNode(rootValue);

        int inIndex = inorderMap[rootValue]; // Find root in inorder array

        // Recursively build left and right subtrees
        root->left = buildTreeHelper(preorder, inorder, inStart, inIndex - 1);
        root->right = buildTreeHelper(preorder, inorder, inIndex + 1, inEnd);

        return root;
    }

public:
    TreeNode* root;

    // Constructor that builds the tree
    BinaryTree(const std::vector<int>& preorder, const std::vector<int>& inorder) {
        root = nullptr;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i; // Store inorder indices in a map
        }
        root = buildTreeHelper(preorder, inorder, 0, inorder.size() - 1);
    }

    // Inorder traversal for verification
    void inorderTraversal(TreeNode* node) {
        if (node == nullptr) return;
        inorderTraversal(node->left);
        std::cout << node->data << " ";
        inorderTraversal(node->right);
    }

    void inorder() {
        inorderTraversal(root);
    }
};

// Driver Code
int main() {
    std::vector<int> preorder = {1, 2, 4, 5, 3, 6, 7}; // Root → Left → Right
    std::vector<int> inorder  = {4, 2, 5, 1, 6, 3, 7}; // Left → Root → Right

    BinaryTree tree(preorder, inorder);

    std::cout << "Inorder Traversal of Constructed Tree: ";
    tree.inorder();
    std::cout << "\n";

    return 0;
}
