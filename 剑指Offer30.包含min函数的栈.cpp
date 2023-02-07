#include <stack>

class MinStack {
public:
    std::stack<int> a;
    std::stack<int> min_stack_;
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) 
    {
        a.push(x);
        if ( min_stack_.empty() or x < min_stack_.top() ) 
        {
            min_stack_.push(x);
        }
    }
    
    void pop() 
    {
        int tmp = a.top();
        a.pop();
        if ( tmp == min_stack_.top() ) 
        {
            min_stack_.pop();
        }
    }
    
    int top() 
    {
        return a.top();
    }
    
    int min() 
    {
        return min_stack_.top();
    }
};