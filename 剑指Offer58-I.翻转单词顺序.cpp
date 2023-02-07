#include <string>
#include <vector>
#include <deque>
#include <iostream>

//完全用思路一改写的
class Solution {
public:
    std::string reverseWords(std::string s) 
    {
        if (s.empty()) return "";

        s = my_strip(s);
        int i = s.size()-1, j = i;
        std::deque<std::string> tmp;

        while ( i >= 0 )
        {
            while (i >= 0 && s[i] != ' ') i--;
            tmp.push_back(s.substr(i+1, j-i));
            while (i >= 0 && s[i] == ' ') i--;
            j = i;
        }
        
        std::string res;
        while ( !tmp.empty())
        {
            res+=tmp.front();
            tmp.pop_front();
            if (!tmp.empty()) res+=" ";
        }
        return res;
    }

    std::string my_strip(std::string s)
    {
        int i = 0, j = s.size()-1;
        while (i < j && s[i] == ' ') i++;
        while (i < j && s[j] == ' ') j--;
        s = s.substr(i,j-i+1);
        return s;
    }
};

//简化一下
class Solution2 {
public:
    std::string reverseWords(std::string s) 
    {
        if (s.empty()) return "";

        s = my_strip(s);
        int i = s.size()-1, j = i;
        std::string res;

        while ( i >= 0 )
        {
            while (i >= 0 && s[i] != ' ') i--;
            res += s.substr(i+1, j-i) += " ";
            while (i >= 0 && s[i] == ' ') i--;
            j = i;
        }
        if(!res.empty()) res.erase(res.end()-1);
        return res;
    }

    std::string my_strip(std::string s)
    {
        int i = 0, j = s.size()-1;
        while (i < j && s[i] == ' ') i++;
        while (i < j && s[j] == ' ') j--;
        s = s.substr(i,j-i+1);
        return s;
    }
};