// https://practice.geeksforgeeks.org/problems/number-of-coins1824/1

// RECURSIVE
// TC = EXPONENTIAL
class Solution
{
public:
    int count(int idx, int target, int coins[])
    {
        if (idx == 0)
        {
            if (target % coins[0] == 0)
            {
                return target / coins[0];
            }
            else
            {
                // not possible case
                return 1e8;
            }
        }

        int notTake = count(idx - 1, target, coins);

        int take = 1e8;
        if (coins[idx] <= target)
            take = 1 + count(idx, target - coins[idx], coins); // stay on the same idx as there is infinite supply of coins

        return min(take, notTake);
    }

    int minCoins(int coins[], int M, int V)
    {
        int ans = count(M - 1, V, coins);

        if (ans > 1e6)
            return -1;

        return ans;
    }
};


// MEMOIZATION
// TC = O(N * T)
// SC = O(N * T) = O(T)
class Solution
{

public:
    int count(int idx, int target, int coins[], vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (target % coins[0] == 0)
            {
                return target / coins[0];
            }
            else
            {
                return 1e8;
            }
        }

        if (dp[idx][target] != -1)
            return dp[idx][target];

        int notTake = count(idx - 1, target, coins, dp);

        int take = 1e8;
        if (coins[idx] <= target)
            take = 1 + count(idx, target - coins[idx], coins, dp);

        return dp[idx][target] = min(take, notTake);
    }

    int minCoins(int coins[], int M, int V)
    {
        vector<vector<int>> dp(M, vector<int>(V + 1, -1));
        int ans = count(M - 1, V, coins, dp);

        if (ans > 1e6)
            return -1;

        return ans;
    }
};


// TABULATION
// TC = O(N * T)
// SC = O(N * T) + O(N)
class Solution
{
public:
    int minCoins(int coins[], int M, int V)
    {
        vector<vector<int>> dp(M, vector<int>(V + 1, 0));

        for (int target = 0; target <= V; target++)
        {
            if (target % coins[0] == 0)
            {
                dp[0][target] = target / coins[0];
            }
            else
            {
                dp[0][target] = 1e8;
            }
        }

        for (int idx = 1; idx < M; idx++)
        {
            for (int target = 1; target < V + 1; target++)
            {
                int notTake = dp[idx - 1][target];

                int take = 1e8;
                if (coins[idx] <= target)
                    take = 1 + dp[idx][target - coins[idx]];

                dp[idx][target] = min(take, notTake);
            }
        }

        if (dp[M - 1][V] >= 1e6)
            return -1;

        return dp[M - 1][V];
    }
};

