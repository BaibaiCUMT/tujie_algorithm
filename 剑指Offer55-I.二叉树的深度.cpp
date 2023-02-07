#include <algorithm>
#include <iostream>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//直接把按层打印的代码拿过来用了
class Solution {
public:
    int maxDepth(TreeNode* root) 
    {
        std::vector<std::vector<int>> res;
        std::queue<TreeNode*>que;
        if (!root) return 0;
        que.push(root);

        while (!que.empty()) 
        {
            std::vector<int> tmp;
            for(int i = que.size(); i > 0; i--)
            {
                TreeNode *cur = que.front();
                que.pop();
                tmp.push_back(cur->val);
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            res.push_back(tmp);
        }
        return res.size();
    }
};

//把上面代码简单改改：
class Solution2 {
public:
    int maxDepth(TreeNode* root) 
    {
        int res = 0;
        if (!root) return res;
        std::queue<TreeNode*>que;
        que.push(root);

        while (!que.empty()) 
        {
            std::vector<int> tmp;
            for(int i = que.size(); i > 0; i--)
            {
                TreeNode *cur = que.front();
                que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
            res++;
        }
        return res;
    }
};


class Solution3 {
public:
    int maxDepth(TreeNode* root) 
    {
        if (!root) return 0;
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1; 
    }
};