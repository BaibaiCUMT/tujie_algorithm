#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

class Solution {
public:
    char firstUniqChar(std::string s) 
    {
        std::unordered_map<char, bool> dic;
        for (char c : s)
            // dic[c] = (dic.find(c) == dic.end());
            if (dic.find(c) == dic.end()) dic[c] = true;
            else dic[c] = false;
        
        for (char c : s)
            if (dic[c]) return c;
        return ' ';
    }
};

//也是n方，但第二次稍微快一点
class Solution2 {
public:
    char firstUniqChar(std::string s) 
    {
        std::vector<char> keys;
        std::unordered_map<char, bool> dic;

        for (char c : s)
        {
            if (dic.find(c) == dic.end()) keys.push_back(c);
            if (dic.find(c) == dic.end()) dic[c] = true;
            else dic[c] = false;
        }

        for (char c : keys)
            if (dic[c]) return c;
        return ' ';
    }
};