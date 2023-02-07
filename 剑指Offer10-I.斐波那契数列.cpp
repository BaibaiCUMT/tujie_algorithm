#include <vector>
#include <iostream>


//注意vector不能直接[]赋值，因为这玩意是变长度的，会指向还不够长的位置
//使用resize()也不行，这个不知道为啥
//使用push_back就好了
class Solution {
public:
    int fib(int n) 
    {
        std::vector<int> dp;
        dp.push_back(0), dp.push_back(1);
        for (int i = 2; i <= n; i++) 
        {
            dp.push_back((dp[i-1] + dp[i-2])%1000000007);
        }
        return dp[n];
    }
};