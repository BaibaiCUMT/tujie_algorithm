#include <algorithm>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

//我们使用先序遍历先去遍历这棵树，当找到p和q就停下，递归回去，并记录下来；
//如果我们只找到一个节点，那么另一个节点必定在该节点的子树内，那么返回该节点就是结果
//如果我们找到了两个节点，说明两个节点都不在相互的子树内，那么

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if (root == nullptr || root == p || root == q) return root;
        TreeNode* A = lowestCommonAncestor(root->left,p,q);
        TreeNode* B = lowestCommonAncestor(root->right, p, q);

        
        if (A == nullptr) return B;
        else if (B == nullptr) return A;
        else return root;
    }
};