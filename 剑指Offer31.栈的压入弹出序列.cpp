#include <iterator>
#include <vector>
#include <stack>


class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) 
    {
        std::stack<int> stk;
        int i = 0;

        for (int num : pushed)
        {
            stk.push(num);
            while ( !stk.empty() && stk.top() == popped[i])
            {
                stk.pop();
                i++;
            }
        }
        return stk.empty();
    }
};



class Solution2 {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) 
    {
        std::stack<int> stk;
        int i = 0;

        for (int num : pushed)
        {
            stk.push(num);
            while (!stk.empty() && stk.top() == popped[i])
            {
                stk.pop();
                i++;
            }
        }
        return stk.empty();
    }
};