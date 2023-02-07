#include <vector>
#include <stack>
#include <algorithm>

 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        while ( cur != nullptr ) 
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};