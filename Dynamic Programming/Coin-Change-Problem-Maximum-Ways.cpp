// Problem Link: https://leetcode.com/problems/coin-change-2/

// Coin Change - Maximum number of ways
// Unbounded Knapsack variation + Count total Subset with target Sum

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();

        int dp[n + 1][amount + 1];

        for (int i = 0; i < amount + 1; i++)
        {
            dp[0][i] = 0;
        }

        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < amount + 1; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][amount];
    }
};