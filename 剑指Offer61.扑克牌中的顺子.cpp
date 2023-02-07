#include <algorithm>
#include <vector>
#include <unordered_set>

//排序法
class Solution {
public:
    bool isStraight(std::vector<int>& nums) 
    {
        int joker = 0;
        std::sort(nums.begin(),nums.end());

        for (int i = 0; i < nums.size()-1; i++) 
        {
            if (nums[i] == 0) joker++;
            else if (nums[i] == nums[i+1]) return false;
        }
        return nums[nums.size()-1] - nums[joker] < 5;
    }
};


//用一个无序集合,可以不用排序，只遍历一次
class Solution2 {
public:
    bool isStraight(std::vector<int>& nums) 
    {
        int ma = 0, mi = 14;
        std::unordered_set<int> tmp;
        for (int num : nums)
        {
            if (num == 0) continue;
            ma = std::max(ma, num);
            mi = std::min(mi, num);
            if (tmp.find(num) != tmp.end()) return false;
            tmp.insert(num);
        }
        return ma - mi < 5;
    }
};