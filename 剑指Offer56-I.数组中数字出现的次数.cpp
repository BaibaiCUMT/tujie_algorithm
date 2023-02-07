#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {
public:
    std::vector<int> singleNumbers(std::vector<int>& nums) 
    {
        int x = 0, y = 0;
        int tmp = 0;
        for (int num : nums) tmp ^= num;
        int m = 1;
        while ( (tmp&m) ==0 ) m <<= 1;
        for (int num: nums) 
        {
            if (num & m) x ^= num;
            else y ^= num;
        }
        return std::vector<int> {x, y};
    }
};


class Solution2 {
public:
    std::vector<int> singleNumbers(std::vector<int>& nums) 
    {
        int x = 0, y = 0;
        int tmp = 0;
        for (int num : nums) tmp ^= num;
        int m = 1;
        
        while ( (tmp&m) == 0) m <<= 1;

        for (int num: nums)
        {
            if ((num & m) != 0) x ^= num;
            else y ^= num;
        }
        return std::vector<int> {x,y};
    }
};

//这是最简单的使用字典解决的办法
class Solution3 {
public:
    std::vector<int> singleNumbers(std::vector<int>& nums) 
    {
        std::unordered_map<int, int> dic;
        for (int i = 0; i < nums.size(); i++) 
        {
            if (dic[nums[i]]) dic[nums[i]]++;
            else dic[nums[i]] = 1;
        }

        std::vector<int> res;
        for (auto [k,v] : dic)
        {
            if (v == 1) res.push_back(k);
        }
        return res;
    }
};