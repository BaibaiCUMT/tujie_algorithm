#include <vector>

class Solution {
public:
    int numWays(int n) 
    {
        std::vector<int> dp;
        dp.push_back(1), dp.push_back(1), dp.push_back(2);
        for (int i = 3; i <= n; i++) 
        {
            dp.push_back( (dp[i-1]+dp[i-2])%1000000007 );
        }
        return dp[n];
    }
};