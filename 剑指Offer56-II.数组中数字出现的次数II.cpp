#include <vector>
#include <unordered_map>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) 
    {
        std::unordered_map<int, int>dic;
        for (int num :nums)
        {
            if (dic[num]) dic[num]++;
            else dic[num] = 1;
        }
        
        for (auto [k,v] :dic) if (v == 1) return k;
        return -1;
    }
};