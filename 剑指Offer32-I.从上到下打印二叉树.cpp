#include <iostream>
#include <vector>
#include <queue>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> levelOrder(TreeNode* root) 
    {
        std::vector<int>res;
        if (!root) return res;

        std::queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) 
        {
            TreeNode * node = que.front();
            que.pop();
            res.push_back(node->val);
            if (node->left) que.push(node->left);
            if (node->right) que.push(node->right);
        }
        return res;
    }
};