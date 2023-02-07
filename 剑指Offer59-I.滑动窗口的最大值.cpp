#include <vector>
#include <stack>

//做这种一定范围内找最大最小的题，注意我们需不需要次大的，否则一些情况会丢失
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) 
    {
        std::vector<int> res;
        std::deque<int> tmp;

        for (int i = 1-k, j = 0; j < nums.size(); i++, j++) 
        {
            if (i > 0 && nums[i-1] == tmp.front()) tmp.pop_front();
            while ( !tmp.empty() && nums[j] > tmp.back()) tmp.pop_back();
            tmp.push_back(nums[j]);
            if (i >= 0) res.push_back(tmp.front());
        }
        return res;
    }
};