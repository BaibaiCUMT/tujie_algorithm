#include <vector>

struct TreeNode {
int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x),left(left), right(right) {}
 };


class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) 
    {
        std::vector<int>res;
        postOrder(root, res);
        return res;
    }

    void postOrder(TreeNode* root, std::vector<int>& res)
    {
        if (root == nullptr) return;
        postOrder(root->left, res);
        postOrder(root->right, res);
        res.push_back(root->val);
    }
};