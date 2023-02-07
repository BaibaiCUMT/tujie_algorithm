#include <iostream>
#include <vector>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    std::vector<TreeNode *> tmp;
    int kthLargest(TreeNode* root, int k) 
    {
        dfs(root);
        return tmp[tmp.size()-k]->val;
    }

    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root->left);
        tmp.push_back(root);
        dfs(root->right);
    }
};

//我的思路是对的，但是递归的过程中，k作为参数定不准确；这是因为当一层函数结束后，我们将从栈中取出暂存的root和k，而这个k是之前存好的，没有被编辑的；

// class Solution2 {
// public:
//     int res;
//     int kthLargest(TreeNode* root, int k) 
//     {
//         dfs(root, k);
//         return res;
//     }

//     void dfs(TreeNode *root, int k)
//     {
//         if (!root) return;
//         dfs(root->right, k);
//         if (k == 0) return;
//         if (k == 1) res = root->val;
//         k--;
//         dfs(root->left, k);
//     }
// };

class Solution2 {
public:
    int res, k;

    int kthLargest(TreeNode* root, int k) 
    {
        this->k = k;
        dfs(root);
        return res;
    }
    
    void dfs(TreeNode* root)
    {
        if (!root) return;
        dfs(root->right);
        if (k == 0) return; //对于已经找到结果的时候，可以直接结束遍历了；方法是一层一层的return, 为啥不是<=呢，因为k=0走到这就结束了，不会再--了；
        if (k == 1) res = root->val;
        k--;
        dfs(root->left);
    }
};

