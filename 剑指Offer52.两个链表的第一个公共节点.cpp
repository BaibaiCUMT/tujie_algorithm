#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

//一个简单的笨办法，但是需要两遍n
//先同位，后比较
//这个方法使用辅助栈会更好
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *a = headA;
        ListNode *b = headB;
        int na = 0;
        int nb = 0;

        while (a != nullptr)
        {
            na++;
            a = a->next;
        }
        while (b != nullptr)
        {
            nb++;
            b = b->next;
        }

        int tmp = na-nb;
        if (tmp > 0)
        {
            while (tmp != 0)
            {
                headA = headA->next;
                tmp--;
            }
        }
        else
        {
            while (tmp != 0) 
            {
                headB = headB->next;
                tmp++;
            }
        }

        while (headA != nullptr)
        {
            if (headA == headB)
            {
                return headA;
            } 
            else 
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return nullptr;
    }
};

//headA 和 headB 共同拥有 c 个节点
//headA 共有 m 个节点, 私有 a 个， m = a + c
//headB 共有 n 个节点， 私有 b 个, n = b + c
//让 指针A 走过所有节点一次,第二次到达公共节点时 共计a+c+b步
//让 指针B 走过所有节点一次,第二次到达公共节点时 共计b+c+a步
//a+c+b = b+c+a, 还是不太懂。

//其实这个题目本质的点还是要让两个路线一样长，当两条线不一样长时，他俩相加的结果一定是一样长的，5+6 = 6+5，假设最后三个是公共节点，那么两个11的最后三个也是公共节点，这样就一样长了。
class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        ListNode *A = headA, *B = headB;
        while ( A != B) 
        {
            A = (A != nullptr)? A->next : headB;
            B = (B != nullptr)? B->next : headA;
        }
        return A;
    }
};