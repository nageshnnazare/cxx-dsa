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

int findMaxDiameter(TreeNode* root, int& maxima) {
    if (root == nullptr) return 0;

    int lh = findMaxDiameter(root->left, maxima);
    int rh = findMaxDiameter(root->right, maxima);
    maxima = std::max(maxima, lh + rh);

    return 1 + std::max(lh, rh);
}

int main(int argc, char const* argv[]) {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    int diameter = -1;

    findMaxDiameter(root, diameter);
    std::cout << "Diameter of the Tree : " << diameter << std::endl;

    return 0;
}
