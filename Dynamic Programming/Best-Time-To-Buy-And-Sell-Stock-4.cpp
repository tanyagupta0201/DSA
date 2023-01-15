// WITH K TRANSACTION

/*
OBSERVATIONS💙:

There are 3 states possible:
skip
buy
sell
but since I cannot buy unless I sell the previous stock, hence for every day I just have 2 possiblities:
buy or skip in case no stock is in hand

sell or skip if we have already bought a stock

the recursive tree would look something like this:
image

there are 3 changing parameters: k, index, buy/sell state
rather than making this 3D dp question with 3 changing parameters, we can combine k and buy/sell state into one variable called transaction ID.
for k = 3, transaction IDs are 0, 1, 2, 3, 4, 5, 6. Here, 0 means the point where first buy should happen and 1 is the point where first sell should happen. Likewise, 2 is the point where 2nd buy should happen,.... so on and so forth.
so if the transaction ID is 3 than it means I have done 1 transaction completely and I have bought 2nd stock which need to be sold.
even signifies stock is to be bought and odd transaction ID signifies stock has to be sold
*/


// RECURSION

Int recursive(vector<int> &prices, int i, int profit, int transID, int cap)
{
        if(cap == 0 || i == prices.size()) 
             return profit; // base case
        
        if(transID & 1) 
        { // buy or no state
            return max(recursive(prices, i + 1, profit + prices[i], transID + 1, cap - 1),
                   recursive(prices, i + 1, profit, transID, cap));
        }
        // sell or no state
        return max(recursive(prices, i + 1, profit - prices[i], transID + 1, cap), 
                   recursive(prices, i + 1, profit, transID, cap));
        
    }
    
    int maxProfit(vector<int>& prices, int k) 
    {
        return recursive(prices, 0, 0, 0, k);
    }


// MEMOIZATION

int memoizationFn(vector<int> &prices, int i, int transID, int cap) 
{
        if(cap == 0 || i == prices.size()) 
             return 0; // base case
        
        if(memo[i][transID] != -1) 
             return memo[i][transID];
        
        if(transID & 1) 
        { // sell or no state
            return memo[i][transID] = 
               max(prices[i] + memoizationFn(prices, i + 1,  transID + 1, cap - 1),
                   memoizationFn(prices, i + 1, transID, cap));
            }
        // buy or no state
        return memo[i][transID] = 
               max(-prices[i] + memoizationFn(prices, i + 1, transID + 1, cap), 
                   memoizationFn(prices, i + 1, transID, cap));
        
    }
    
    int maxProfit(vector<int>& prices, int k) 
    {
        int cap = k;
        memo.resize(prices.size(), vector<int>(2 * cap, -1));
        return memoizationFn(prices, 0, 0, cap);
    }


// TABULATION

int maxProfit(vector<int>& prices, int k) 
{
        int cap = k;
        int n = prices.size();
        vector<vector<int>> dp;
        dp.resize(prices.size() + 1, vector<int>(2 * cap + 1, 0));
        
        for(int i = n - 1; i >= 0; i--) {
            for(int transID = 2*cap - 1; transID >= 0; transID--) {
                if(transID & 1) { // sell or no state
                    dp[i][transID] = 
                       max(prices[i] + dp[i + 1][transID + 1],
                                       dp[i + 1][transID]);
                }
            // buy or no state
                else {
                    dp[i][transID] = 
                        max(-prices[i] + dp[i + 1][transID + 1], 
                                         dp[i + 1][transID]);
                }
            }
        }
        
        return dp[0][0];
    }
};
