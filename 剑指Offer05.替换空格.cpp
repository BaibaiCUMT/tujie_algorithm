#include <string>

class Solution {
public:
    std::string replaceSpace(std::string s) 
    {
        std::string res;
        for (int i = 0; i < s.length(); i++) 
        {
            if (s[i] == ' ') 
            {
                res.append("%20");
            }
            else {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};