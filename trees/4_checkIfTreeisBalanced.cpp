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

int checkIfBinaryTreeIsBalanced(TreeNode* root) {
    if (root == nullptr) return 0;

    int lh = checkIfBinaryTreeIsBalanced(root->left);
    int rh = checkIfBinaryTreeIsBalanced(root->right);

    if (lh == -1 || rh == -1) return -1;

    if (abs(lh - rh) > 1) return -1;

    return std::max(lh, rh) + 1;
}

int main(int argc, char const* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    std::cout << "Tree (1) Balanced : "
        << (checkIfBinaryTreeIsBalanced(root) > 0 ? "Yes" : "No")
        << std::endl;


    root->left->left->left = new TreeNode(5);
    std::cout << "Tree (2) Balanced : "
        << (checkIfBinaryTreeIsBalanced(root) > 0 ? "Yes" : "No")
        << std::endl;


    return 0;
}
