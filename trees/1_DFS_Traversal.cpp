#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {};
    TreeNode(int val, TreeNode* left) : val(val), left(left), right(nullptr) {};
    TreeNode(int val, TreeNode* left, TreeNode* right) : val(val), left(left), right(right) {};
};

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->val << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    std::cout << root->val << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->val << " ";
}

int main(int argc, char const* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    std::cout << "Pre-order Traversal : " << std::endl;
    preOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "In-order Traversal : " << std::endl;
    inOrderTraversal(root);
    std::cout << std::endl;

    std::cout << "Post-order Traversal : " << std::endl;
    postOrderTraversal(root);
    std::cout << std::endl;

    return 0;
}
