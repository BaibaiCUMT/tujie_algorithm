#include <cstddef>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


//从-1开始
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) 
    {
        if (head->val == val) return head->next;

        ListNode *pre = nullptr, *cur = head;
        while ( cur->val != val ) 
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        return head;
    }
};


//从0开始
class Solution2 {
public:
    ListNode* deleteNode(ListNode* head, int val) 
    {
        if (head->val == val) return head->next;

        ListNode *pre = head, *cur = head->next;
        while (cur->val != val)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
        return head;
    }
};