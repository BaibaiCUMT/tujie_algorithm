#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    bool isBalanced(TreeNode* root) 
    {
        if (!root) return true;
        return isBalanced(root->left) && isBalanced(root->right) && abs(getDepth(root->left) - getDepth(root->right)) < 2;
    }

    int getDepth(TreeNode* root)
    {
        if (!root) return 0;
        return std::max(getDepth(root->left), getDepth(root->right)) + 1;
    }
};