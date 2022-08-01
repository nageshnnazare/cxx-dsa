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

int maxPathSum(TreeNode* root, int& maxima) {
    if (root == nullptr) return 0;

    int lsum = std::max(0, maxPathSum(root->left, maxima));
    int rsum = std::max(0, maxPathSum(root->right, maxima));

    maxima = std::max(maxima, lsum + rsum + root->val);

    return root->val + std::max(lsum, rsum);
}

int main(int argc, char const* argv[]) {
    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    int pathSum = -1;
    maxPathSum(root, pathSum);

    std::cout << "Max path sum : " << pathSum << std::endl;

    return 0;
}