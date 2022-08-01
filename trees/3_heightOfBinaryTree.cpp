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

int heightOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;

    return std::max(heightOfBinaryTree(root->left), heightOfBinaryTree(root->right)) + 1;

}

int main(int argc, char const* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);

    std::cout << "Height of the Tree : "
        << heightOfBinaryTree(root) << std::endl;

    return 0;
}
