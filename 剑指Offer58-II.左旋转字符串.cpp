#include <algorithm>
#include <string>
#include <deque>

class Solution {
public:
    std::string reverseLeftWords(std::string s, int n) 
    {
        std::reverse(s.begin(), s.begin()+n );
        std::reverse(s.begin()+n, s.end());
        std::reverse(s.begin(), s.end());
        return s;
    }
};