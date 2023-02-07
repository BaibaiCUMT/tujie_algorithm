#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) 
    {
        ListNode *pre = head, *cur = head;

        while (k > 0) 
        {
            cur = cur->next;
            k--;
        }
        
        while (cur != nullptr) 
        {
            cur = cur->next;
            pre = pre->next;
        }
        return pre;
    }
};