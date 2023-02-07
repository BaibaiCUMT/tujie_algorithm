#include <vector>
#include <iostream>

//这法子可以，但是超慢超大
class Solution {
public:
    std::vector<std::vector<int>> findContinuousSequence(int target) 
    {
        std::vector<std::vector<int>> res;

        for (int i = 1; i < target; i++) 
        {
            int sum = 0;
            std::vector<int> tmp;
            for (int j = i; j < target; j++) 
            {
                sum += j;
                tmp.push_back(j);
                if (sum == target) 
                {
                    res.push_back(tmp);
                    tmp.clear();
                    sum = 0;
                    break;
                }
                if (sum > target)
                {
                    tmp.clear();
                    sum = 0;
                    break;
                }
            }
        }
        return res;
    }
};


class Solution2 {
public:
    std::vector<std::vector<int>> findContinuousSequence(int target) 
    {
        int i = 1, j = 2, s = 3;
        std::vector<std::vector<int>> res;

        while ( i < j ) 
        {
            if (s == target) 
            {
                std::vector<int> tmp;
                for (int k = i; k <= j; k++) tmp.push_back(k);
                res.push_back(tmp);
            }

            if (s < target)
            {
                j++;
                s += j;
            }
            else if (s >= target) //这里为什么是>=：因为s==target的时候会进入死循环，我们需要变动一下让循环继续，这也是找到第一个结果后，开始找第二个结果的要求。
            {
                s -= i;
                i++;
            }
        }
        return res;
    }
};

//双指针的另一种写法：
class Solution21 {
public:
    std::vector<std::vector<int>> findContinuousSequence(int target) 
    {
        int i = 1, j = 2, s = 3;
        std::vector<std::vector<int>> res;

        while ( i < j ) 
        {
            if (s == target) 
            {
                std::vector<int> tmp;
                for (int k = i; k <= j; k++) tmp.push_back(k);
                res.push_back(tmp);
                s -= i;
                i++;
            }
            if (s < target)
            {
                j++;
                s += j;
            }
            else if ( s > target)
            {
                s -= i;
                i++;
            }
        }
        return res;
    }
};