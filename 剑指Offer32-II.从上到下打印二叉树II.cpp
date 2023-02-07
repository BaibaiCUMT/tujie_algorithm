#include <vector>
#include <iostream>
#include <queue>
 
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
            res.push_back(tmp);
        }
        return res;
    }
};


//自己写
class Solution2 {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root) 
    {
        std::vector<std::vector<int>> res;
        std::queue<TreeNode*>que;
        if (!root) return res;
        que.push(root);

        while (!que.empty()) 
        {
            std::vector<int> tmp;
            for(int i = que.size(); i > 0; i--) //如果用for(int i = 0; i < que.size(); i++) 我们再循环中改变了que.size()就会使循环不准
            {
                TreeNode *cur = que.front();
                que.pop();
                tmp.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            res.push_back(tmp);
        }
        return res;
    }
};