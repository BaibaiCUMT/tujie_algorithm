
#include <deque>

class MaxQueue {
public:
    std::deque<int> res;
    std::deque<int> tmp;
    MaxQueue() { }
    
    int max_value() 
    {
        return tmp.empty() ? -1 : tmp.front();
    }
    
    void push_back(int value) 
    {
        res.push_back(value);
        while ( !tmp.empty() && tmp.back() < value) tmp.pop_back();
        tmp.push_back(value);
    }
    
    int pop_front() 
    {
        if (res.empty()) return -1;
        int val = res.front();
        if (val == tmp.front()) tmp.pop_front();
        res.pop_front();
        return val; 
    }
};