#include <string>
#include <vector>
#include <algorithm>

//这里是仿函数，
//使用谓词仿函数的方法是最常用的，调用时创建了一个匿名的实例化对象。
class Solution {
public:
    bool operator()(const std::string &s1,const std::string &s2)
    {
        return s1+s2 < s2+s1;
    }

    std::string minNumber(std::vector<int>& nums) 
    {
        std::vector<std::string> strs;
        std::string res;

        for (int i = 0; i < nums.size(); i++) 
            strs.push_back(std::to_string(nums[i]));
        
        std::sort(strs.begin(), strs.end(), Solution()); //此处Solution()创建了一个匿名对象，这是使用仿函数的常规操作。

        for (int i = 0; i < strs.size(); i++)
            res.append(strs[i]);
        
        return res;
    }
};



//这是是普通函数 放在类内
class Solution2 {
public:
    static bool compare(const std::string &s1,const std::string &s2)
    {
        return s1+s2 < s2+s1;
    }

    std::string minNumber(std::vector<int>& nums) 
    {
        std::vector<std::string> strs;
        std::string res;

        for (int i = 0; i < nums.size(); i++) 
            strs.push_back(std::to_string(nums[i]));
        
        std::sort(strs.begin(), strs.end(), compare);

        for (int i = 0; i < strs.size(); i++)
            res.append(strs[i]);
        
        return res;
    }
};



//这是是普通函数 放在类外
bool compare(const std::string &s1,const std::string &s2)
    {
        return s1+s2 < s2+s1;
    }

class Solution3 {
public:
    std::string minNumber(std::vector<int>& nums) 
    {
        std::vector<std::string> strs;
        std::string res;

        for (int i = 0; i < nums.size(); i++) 
            strs.push_back(std::to_string(nums[i]));
        
        std::sort(strs.begin(), strs.end(), compare);

        for (int i = 0; i < strs.size(); i++)
            res.append(strs[i]);
        
        return res;
    }
};
