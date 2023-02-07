#include <vector>


class Solution {
public:
    int findPeakElement(std::vector<int>& nums) 
    {
        //使用常规的模板3和模板一均不能完成此题，对于一个元素和两个元素的判断始终有问题；
        if (nums.size() == 1) return 0;

        int i = -1, j = nums.size();
        while (i+1 != j)
        {
            int m = i + ((j-i)>>1);
            if (nums[m] < nums[m+1]) i = m;
            else j = m;
        }
        return j;
    }
};