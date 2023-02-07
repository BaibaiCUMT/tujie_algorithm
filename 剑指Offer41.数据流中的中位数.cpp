#include <algorithm>
#include <functional>
#include <queue>
#include <vector>


//首先我们确实使用大小根堆来解决问题，大根堆存小数，小根堆存大数；
//其次我们选择奇数是选取小根堆的首位做答案；

//我们希望往两个堆内分别添加元素，先加小根堆，再加大根堆；
//当我们到达向小根堆内添加数字的轮次时，我们希望小根堆添加的数是大根堆内最大的数，即我们需要已经加工过的数字，而不是新的未知数，否则会让两个数据结构的序列不符；
//所以先向另一个堆添加元素，然后弹出栈顶，加入另一个堆即可；

class MedianFinder {
public:
    /** initialize your data structure here. */
    
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_root; //越大越往后排，小根堆
    std::priority_queue<int, std::vector<int>> big_root; //越小越往后，大根堆
    MedianFinder() { }
    
    void addNum(int num) 
    {
        if (big_root.size() != small_root.size()) 
        {
            small_root.push(num);
            big_root.push(small_root.top());
            small_root.pop();
        }
        else 
        {
            big_root.push(num);
            small_root.push(big_root.top());
            big_root.pop();
        }
    }
    
    double findMedian() 
    {
        return small_root.size() == big_root.size() ? ((small_root.top() + big_root.top()) / 2.0 ) : small_root.top();
    }
};


//再写一遍
class MedianFinder2 {
public:
    std::priority_queue<int, std::vector<int>> big_root;
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_root;
    MedianFinder2() { }
    
    void addNum(int num) 
    {
        if (big_root.size() == small_root.size())
        {
            big_root.push(num);
            small_root.push(big_root.top());
            big_root.pop();
        }
        else 
        {
            small_root.push(num);
            big_root.push(small_root.top());
            small_root.pop();    
        }
    }
    
    double findMedian() 
    {
        return big_root.size() == small_root.size() ? (big_root.top() + small_root.top()) / 2.0 : small_root.top();
    }
};