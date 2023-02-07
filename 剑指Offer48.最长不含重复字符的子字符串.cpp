#include <string>
#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

//本题思路
//用一个unordered_map记录已经经过的值，当新值不在map中，非重复字符串长度+1

//当新值在map中，就出现了重复的情况，这时我们需要获得两个重复值之间的距离;
//若距离大于dp[i-1]就说明前字符已经不在非重复字符串里了，dp[i]=dp{i-1]+1即可.
//若距离小于dp[i-1]就说明前字符还在非重复字符串中，dp[i]=i-j.

//这个解法的一个问题在于，dp的定义是以Xi为尾的字符串的最长非重复子字符串的长度为dp[i]，而这个解法将dp设为dp[i] = i-j时，是不是不符合我们对dp下的定义
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) 
    {
        if (s.empty()) return 0;

        std::vector<int> dp;
        dp.push_back(1);

        std::unordered_map<char, int> sub;
        sub[s[0]] = 0;
        for (int i = 1; i < s.size(); i++) 
        {
            if (sub.find(s[i]) == sub.end())
            {
                dp.push_back(dp[i-1]+1);
            }
            else 
            {
                int left = sub.find(s[i])->second;
                if ( (i-left) <= dp[i-1] ) dp.push_back(i-left);
                else dp.push_back(dp[i-1]+1);
            }
            sub[s[i]] = i;
        }
        return *std::max_element(dp.begin(),dp.end());
    }
};