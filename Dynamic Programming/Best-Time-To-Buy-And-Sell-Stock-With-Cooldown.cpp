// MEMOIZATION
// TC = O(N * 2), SC = O(N * 2) + O(N)

class Solution {
public:
    int f(int idx, int buy, int n, vector<int> &prices, vector<vector<int>> &dp)
    {
        if(idx >= n)
            return 0;
        
        int profit = 0;
        
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        
        if(buy == 1)
        {
            // buy
            profit = max( -prices[idx] + f(idx + 1, 0, n, prices, dp), 0 + f(idx + 1, 1, n, prices, dp));   
        }
        else
        {
            // sell
            // (idx + 2) is done because there is a colldown, next index cannot be buyed
            profit = max( prices[idx] + f(idx + 2, 1, n, prices, dp), 0 + f(idx + 1, 0, n, prices, dp));   
        }
        
        return dp[idx][buy] = profit;
    }
    
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        
        // idx -> 0 to (n - 1), buy -> 0 or 1
        vector<vector<int>> dp(n, vector<int> (2, -1));
        
        return f(0, 1, n, prices, dp);
    }
};



// TABULATION
// TC = O(N * 2), SC = O(N * 2)

class Solution {
public:    
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        
        // idx -> 0 to (n - 1), buy -> 0 or 1
        // (n + 2) size is taken because in selling portion we are doing (idx + 2)
        vector<vector<int>> dp(n + 2, vector<int> (2, 0));
        
        dp[n][0] = 0;
        dp[n][1] = 0;
        
        for(int idx = n - 1; idx >= 0; idx--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;

                if(buy == 1)
                {
                    profit = max( -prices[idx] + dp[idx + 1][0] , 0 + dp[idx + 1][1] );   
                }
                else
                {
                    profit = max( prices[idx] + dp[idx + 2][1], 0 + dp[idx + 1][0] );   
                }

                dp[idx][buy] = profit;
            }
        }
        
        return dp[0][1];
    }
};


