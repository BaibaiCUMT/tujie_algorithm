#include <algorithm>
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
    std::vector<int> path;
    std::vector<std::vector<int>> res;

    std::vector<std::vector<int>> pathSum(TreeNode* root, int target) 
    {
        recur(root, target);
        return res;
    }

    void recur(TreeNode* root, int target)
    {
        if (!root) return;
        path.push_back(root->val);
        target -= root->val;
        if (target == 0 && root->left == nullptr && root->right == nullptr) res.push_back(path);
        recur(root->left, target);
        recur(root->right, target);
        path.pop_back();
    }
};




class Solution2 {
public:

    std::vector<int> path;
    std::vector<std::vector<int>> res;

    std::vector<std::vector<int>> pathSum(TreeNode* root, int target) 
    {
        dfs(root, target);
        return res;
    }

    void dfs(TreeNode *root, int target)
    {
        if (!root) return;
        path.push_back(root->val);
        target -= root->val;
        if (target == 0 && !root->left && !root->right) res.push_back(path);
        dfs(root->left, target);
        dfs(root->right, target);
        path.pop_back();
    }
};

class Solution3 {
public:

    std::vector<int> path;
    std::vector<std::vector<int>> res;

    std::vector<std::vector<int>> pathSum(TreeNode* root, int target) 
    {
        dfs(root, target);
        return res;
    }

    void dfs(TreeNode* root, int target)
    {
        if (!root) return;
        path.push_back(root->val);
        target -= root->val;
        if (target == 0 && !root->left && !root->right) res.push_back(path);
        dfs(root->left, target);
        dfs(root->right, target);
        path.pop_back();
    }
};