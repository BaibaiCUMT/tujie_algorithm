#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) 
    {
        int i = -1, j = nums.size();

        while (i+1 != j)
        {
            int m = i + ((j-i)>>1);
            if (nums[m] <= m) i = m;
            else if (nums[m] > m) j = m;
        }
        return i+1;
    }
};