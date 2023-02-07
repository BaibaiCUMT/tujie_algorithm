#include <iostream>
#include <vector>
#include <deque>

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    std::vector<Node *> tmp;

    Node* treeToDoublyList(Node* root) 
    {
        if (!root) return nullptr;
        recur(root);
        
        for (int i= 0; i < tmp.size()-1; i++) 
        {
            int j = i+1;
            tmp[i]->right = tmp[j];
            tmp[j]->left = tmp[i];
        }

        Node * head = tmp[0];
        tmp[0]->left = tmp[tmp.size()-1];
        tmp[tmp.size()-1]->right = tmp[0];

        return head;
    }

    void recur(Node* root)
    {
        if (!root) return;
        recur(root->left);
        tmp.push_back(root);
        recur(root->right);
    }
};

class Solution2 {
public:
    Node* treeToDoublyList(Node* root) 
    {
        if (!root) return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    Node *head, *pre;
    void dfs(Node* cur)
    {
        if (!cur) return;
        dfs(cur->left);
        if (pre == nullptr) head = cur;
        else
        {
            pre->right = cur;
            cur->left = pre;
        }
        pre = cur;
        dfs(cur->right);
    }
};