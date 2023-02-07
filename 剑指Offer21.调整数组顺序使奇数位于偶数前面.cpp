#include <vector>


//思路简单，但是对于边界的控制还是有点难度。常思常新
class Solution {
public:
    std::vector<int> exchange(std::vector<int>& nums) 
    {
        int i = 0, j = nums.size()-1;
        while (i < j)
        {
            while (i < j && nums[i] % 2 != 0 ) i++;
            while (i < j && nums[j] % 2 == 0 ) j--;
            if (i < j) swap(nums[i], nums[j]);
        }
        return nums;
    }

    void swap(int &i, int &j)
    {
        int tmp = i;
        i = j;
        j = tmp;
    }
};


class Solution2 {
public:
    std::vector<int> exchange(std::vector<int>& nums) 
    {
        int i = 0, j = nums.size()-1;
        while (i < j)
        {
            while (i < j && nums[i]%2 != 0) i++;
            while (i < j && nums[j]%2 == 0) j--;
            if (i < j) std::swap(nums[i],nums[j]);
        }
        return nums;
    }
};