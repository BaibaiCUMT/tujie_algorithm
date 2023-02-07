#include <vector>

//用while套while
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        int i = 0, j = nums.size()-1;

        while (i < j)
        {
            while (nums[i] + nums[j] > target) j--;
            while (nums[i] + nums[j] < target) i++;
            if (nums[i] + nums[j] == target) break;
        }
        return {nums[i],nums[j]};
    }
};

//用while套if
class Solution2 {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        int i = 0, j = nums.size()-1;

        while (i < j)
        {
            int tmp = nums[i] + nums[j];
            if (tmp > target) j--;
            else if (tmp < target) i++;
            else break;
        }
        return {nums[i],nums[j]};
    }
};