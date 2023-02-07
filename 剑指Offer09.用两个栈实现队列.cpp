#include <stack>

class CQueue {
public:
    std::stack<int> a,b;

    CQueue() 
    {
        
    }
    
    void appendTail(int value) 
    {
        a.push(value);
    }
    
    int deleteHead() 
    {
        if (!b.empty()) 
        {
            int res = b.top();
            b.pop();
            return res;
        }
        else if ( b.empty() && !a.empty())
        {
            while (a.empty()) 
            {
                int tmp = a.top();
                b.push(tmp);
                a.pop();
            }
            int res = b.top();
            b.pop();
            return res;
        }
        return -1;
    }
};