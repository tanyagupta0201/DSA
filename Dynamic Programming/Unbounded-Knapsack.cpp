// Problem Link: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1#

class Solution
{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N + 1][W + 1];

        for (int i = 0; i < N + 1; i++)
        {
            for (int j = 0; j < W + 1; j++)
            {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j < W + 1; j++)
            {
                if (wt[i - 1] <= j)
                {
                    // Since it is unbounded Knapsack, we can include 1 item any number of times
                    int inc = val[i - 1] + dp[i][j - wt[i - 1]];
                    // If item is excluded, it can never be included again
                    int exc = dp[i - 1][j];

                    dp[i][j] = max(inc, exc);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[N][W];
    }
};