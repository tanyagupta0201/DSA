// at most two transactions.
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// RECURSIVE
// TC = Exponential, SC = O(N)

class Solution {
public:
    int f(int idx, int buy, int cap, int n, vector<int> &prices)
    {
        if(n == idx)
            return 0;
        
        if(cap == 0)
            return 0;
        
        int profit = 0;
        
        if(buy == 1)
        {
            // buy or do not buy
            profit = max( -prices[idx] + f(idx + 1, 0, cap, n, prices) , 0 + f(idx + 1, 1, cap, n, prices) );
        }
        else
        {
            // sell or do not sell
            // jab sell karenge tab hi toh capacity par farak padega (sirf ussi case mein decrese hogi)
            profit = max( prices[idx] + f(idx + 1, 1, cap - 1, n, prices) , 0 + f(idx + 1, 0, cap, n, prices) );     
        }
        
        return profit;
    }
    
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
      
        // f(idx, buy, capacity, n, prices)
        return f(0, 1, 2, n, prices);
    }
};


// MEMOIZATION
// TC = O(N * M), SC = O(N * M) + O(N)
class Solution {
public:
    int f(int idx, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {
        if(n == idx)
            return 0;
        
        if(cap == 0)
            return 0;
        
        if(dp[idx][buy][cap] != -1)
            return dp[idx][buy][cap];
        
        int profit = 0;
        
        if(buy == 1)
        {
            // buy or do not buy
            profit = max( -prices[idx] + f(idx + 1, 0, cap, n, prices, dp) , 0 + f(idx + 1, 1, cap, n, prices, dp) );
        }
        else
        {
            // sell or do not sell
            // jab sell karenge tab hi toh capacity par farak padega (sirf ussi case mein decrese hogi)
            profit = max( prices[idx] + f(idx + 1, 1, cap - 1, n, prices, dp) , 0 + f(idx + 1, 0, cap, n, prices, dp) );     
        }
        
        return dp[idx][buy][cap] = profit;
    }
    
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        
        // idx -> 0 to (n - 1), buy = 1 or 0, capacity = 2 (possible values = 0, 1, 2)
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int> (3, -1)));
        
        return f(0, 1, 2, n, prices, dp);
    }
};


// TABULATION
// TC = O(N * M), SC = O(N * M) 
class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int n = prices.size();
        
        // idx -> 0 to (n - 1), buy = 1 or 0, capacity = 2 (possible values = 0, 1, 2)
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3, 0)));
        
        // no need to write base cases as already zero is assigned
        
        for(int idx = n - 1; idx >= 0; idx--)
        {
            for(int buy = 0; buy <= 1; buy++)
            {
                for(int cap = 1; cap <= 2; cap++)
                {
                    int profit = 0;
        
                    if(buy == 1)
                    {
                        // buy or do not buy
                        profit = max( -prices[idx] + dp[idx + 1][0][cap] , 0 + dp[idx + 1][1][cap] );
                    }
                    else
                    {
                        // sell or do not sell
                        // jab sell karenge tab hi toh capacity par farak padega (sirf ussi case mein decrese hogi)
                        profit = max( prices[idx] + dp[idx + 1][1][cap - 1], 0 + dp[idx + 1][0][cap] );     
                    }
                    
                    dp[idx][buy][cap] = profit;
                }
            }
        }
        
        return dp[0][1][2];        
    }
};
