#include <algorithm>
#include <vector>
#include <climits>


//策略是，第i天的最大利润是，i-1最大利润和i天的利润的较大值；
class Solution {
public:
    int maxProfit(std::vector<int>& prices) 
    {
        if (prices.empty()) return 0;
        
        std::vector<int> dp;
        dp.push_back(0);

        int cost = INT_MAX;

        for (int i = 1; i < prices.size(); i++) 
        {
            cost = std::min(cost, prices[i-1]);
            dp.push_back(std::max(dp[i-1], prices[i] - cost));
        }
        return dp[prices.size()-1];
    }
};