#include <vector>
#include <stack>
#include <algorithm>


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node *cur = head;

        while ( cur != nullptr) 
        {
            Node *tmp = new Node(cur->val);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }

        cur = head;
        while ( cur != nullptr ) 
        {
            if (cur->random != NULL) 
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;   
        }

        Node *res = cur = head->next;
        Node *pre = head;
        while (cur->next != nullptr) 
        {
            pre->next = pre->next->next;
            cur->next = cur->next->next;
            pre = pre->next;
            cur = cur->next;
        }
        pre->next = nullptr;
        return res;
    }
};