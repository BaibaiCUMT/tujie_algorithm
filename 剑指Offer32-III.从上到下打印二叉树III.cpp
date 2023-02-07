#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) 
    {
        std::vector<std::vector<int>>res;
        if (!root) return res;

        std::queue<TreeNode*>que;
        que.push(root);
        while (!que.empty()) 
        {
            std::vector<int>tmp;
            for (int i = que.size(); i >0; i--) 
            {
                TreeNode *node = que.front();
                que.pop();
                tmp.push_back(node->val);
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
            if (res.size() % 2 != 0) std::reverse(tmp.begin(),tmp.end());
            res.push_back(tmp);
        }
        return res;
    }
};