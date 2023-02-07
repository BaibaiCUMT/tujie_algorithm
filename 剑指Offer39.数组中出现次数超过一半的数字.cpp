#include <vector>
#include <algorithm>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) 
    {
        int x = 0, vote = 0;
        for (int num : nums)
        {
            if (vote == 0) x = num;
            vote += (num == x) ? 1 : -1;
        }
        return x;
    }
};

class Solution2 {
public:
    int majorityElement(std::vector<int>& nums) 
    {
        int x = 0, vote = 0;
        for (int num : nums)
        {
            if (vote == 0) x = num;
            if (num == x) vote ++;
            else vote--;
        }
        return x;
    }
};