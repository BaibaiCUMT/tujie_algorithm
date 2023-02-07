#include <vector>

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) 
    {
        int i = -1, j = nums.size();

        while (i+1 != j) 
        {
            int m = i + ((j - i) >>1);
            if (nums[m] < target) i = m;
            else j = m;
        }
        return j;
    }
};