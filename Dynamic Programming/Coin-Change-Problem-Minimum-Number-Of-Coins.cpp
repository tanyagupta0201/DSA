// Problem Link: https://leetcode.com/problems/coin-change/

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int dp[n + 1][amount + 1];

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= amount; j++)
            {
                // Boundary Cases

                // When amt is zero
                if (j == 0)
                    dp[i][j] = 0;

                // when number of coins are zero
                else if (i == 0)
                    dp[i][j] = 1e5;

                // We can only exclude if the value of coin is greater than the amount
                else if (coins[i - 1] > j)
                    dp[i][j] = dp[i - 1][j];

                // If we have choice for both include and exclude
                else
                    dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
        }

        return dp[n][amount] > 1e4 ? -1 : dp[n][amount];
    }
};