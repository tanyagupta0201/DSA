// Problem Link: https://practice.geeksforgeeks.org/problems/count-all-possible-paths-from-top-left-to-bottom-right3011/1

// Recursive
class Solution
{
public:
    long long int countPaths(int i, int j)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }

        if (i < 0 || j < 0)
        {
            return 0;
        }

        int up = countPaths(i - 1, j);
        int left = countPaths(i, j - 1);

        return (left + up) % 1000000007;
    }

    long long int numberOfPaths(int m, int n)
    {
        return countPaths(m - 1, n - 1);
    }
};

// Memoization
class Solution
{
public:
    long long int countPaths(int i, int j, vector<vector<int>> &dp)
    {
        if (i == 0 && j == 0)
        {
            return 1;
        }

        if (i < 0 || j < 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }

        int up = countPaths(i - 1, j, dp);
        int left = countPaths(i, j - 1, dp);

        return dp[i][j] = (left + up) % 1000000007;
    }

    long long int numberOfPaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return countPaths(m - 1, n - 1, dp);
    }
};

// Tabulation
long long int numberOfPaths(int m, int n)
{
    // code here
    int dp[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = 0;
            int down = 0;

            if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                if (j > 0)
                {
                    down = dp[i][j - 1];
                }
                dp[i][j] = up + down;
            }
        }
    }
    return dp[m - 1][n - 1];
}