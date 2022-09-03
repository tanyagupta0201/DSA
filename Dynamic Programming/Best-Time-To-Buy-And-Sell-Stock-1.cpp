// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        int profit = 0, mini = prices[0];
        
        for(int i = 0; i < n; i++)
        {
            profit = max(profit, prices[i] - mini);
            mini = min(mini, prices[i]);
        }
        
        return profit;
    }
};
