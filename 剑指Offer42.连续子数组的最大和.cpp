#include <vector>
#include <algorithm>

//使用dp的模板来写
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) 
    {
        std::vector<int> dp;
        dp.push_back(nums[0]);

        for (int i = 1; i < nums.size(); i++) 
        {
            dp.push_back(std::max(nums[i], dp[i-1]+nums[i]));
        }
        return *std::max_element(dp.begin(),dp.end());
    }
};

//直接在原数组内更改元素
class Solution2 {
public:
    int maxSubArray(std::vector<int>& nums) 
    {
        for (int i = 1; i < nums.size(); i++)
        {
            nums[i] = (std::max(nums[i], nums[i-1]+nums[i]));
        }
        return *std::max_element(nums.begin(),nums.end());
    }
};