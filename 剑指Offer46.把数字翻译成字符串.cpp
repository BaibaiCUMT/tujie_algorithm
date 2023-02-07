#include <string>
#include <vector>
#include <deque>
#include <iostream>


//对于本题我们想要取部分数字出来，进行比较的时候，强转string为int时，转换的返回值时ascii码，不能使用这种方法进行切分，使用子字符串来切分即可。
class Solution {
public:
    int translateNum(int num) 
    {
        std::string s = std::to_string(num);
        int m = s.size();

        std::vector<int> dp;
        dp.push_back(1), dp.push_back(1);

        for (int i = 2 ; i <= m; i++) 
        {
            std::string tmp = s.substr(i-2,2);
            if (tmp <= ("25") && tmp >= ("10"))
            {
                dp.push_back(dp[i-1] + dp[i-2]);
            }
            else
            {
                dp.push_back(dp[i-1]);
            }
        }
        return dp[m];
    }
};