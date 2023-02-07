#include <iostream>
#include <vector>

class Solution {
public:
    int search(std::vector<int>& nums, int target) 
    {
        int i = 0, j = nums.size();

        while (i <= j) 
        {
            int m = (i +(j-i)>>1);
            if (nums[m] >= target) i = m+1;
            else j = m-1;
        }
        return i;
    }
};