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
    std::vector<int> reversePrint(ListNode* head) 
    {
        std::stack<int> tmp;
        while ( head ) 
        {
            tmp.push(head->val);
            head = head->next;
        }

        std::vector<int> res;
        while ( !tmp.empty() ) 
        {
            res.push_back( tmp.top() );
            tmp.pop();
        }
        
        return res;
    }
};

class Solution2 {
public:
    std::vector<int>res;
    std::vector<int> reversePrint(ListNode* head) 
    {
        recur(head);
        return res;
    }

    void recur(ListNode* head)
    {
        if (not head) return;
        recur(head->next);
        res.push_back(head->val);
    }
};