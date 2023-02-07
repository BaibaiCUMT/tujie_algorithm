#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    std::vector<int> preorder;
    std::unordered_map<int, int> dic;

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
    {
        this->preorder = preorder;
        for (int i = 0; i < inorder.size(); i++) dic[inorder[i]] = i;
        return recur(0, 0, inorder.size()-1);
    }

    TreeNode* recur(int root, int left, int right)
    {
        if (left > right) return nullptr;
        TreeNode* node = new TreeNode(preorder[root]);
        int i = dic[preorder[root]];
        node->left = recur(root + 1, left, i-1);
        node->right = recur(root+i-left+1, i+1, right);
        return node;
    }
};


class Solution2 {
public:
    std::vector<int> preorder;
    std::unordered_map<int, int> dic;

    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
    {
        this->preorder = preorder;
        for (int i = 0; i < inorder.size(); i++) dic[inorder[i]] = i;
        return recur(0, 0, inorder.size()-1);
    }

    TreeNode* recur(int root, int left, int right)
    {
        if (left > right) return nullptr;
        int root_val = preorder[root];
        TreeNode *node = new TreeNode(root_val);
        int root_index = dic[preorder[root]];

        node->left = recur(root+1, left, root_index-1);
        node->right = recur(root+root_index-left+1, root_index+1, right);
        return node;
    }
};