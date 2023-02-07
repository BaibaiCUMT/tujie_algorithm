#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//直接使用了二叉搜索树的性质来解题；
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        while (root != nullptr)
        {
            if (root->val > p->val && root->val > q->val) root = root->left;
            else if (root->val < p->val && root->val < q->val) root = root->right;
            else break;
        }
        return root;
    }
};


class Solution2 {
public:
    TreeNode* res;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        recur(root, p, q);
        return res;
    }

    void recur(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr) return;
        if (root->val > p->val && root->val > q->val) recur(root->left,p,q);
        else if (root->val < p->val && root->val < q->val) recur(root->right,p,q);
        else res = root;
    }
};

//更简洁的办法：
class Solution3 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q); 
        return root;
    }
};