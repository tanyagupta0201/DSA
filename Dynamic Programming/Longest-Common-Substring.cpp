// https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1

// RECURSIVE

class Solution
{
public:
    int func(string s1, string s2, int n, int m, int count)
    {
        if (n == 0 || m == 0)
            return count;

        if (s1[n - 1] == s2[m - 1])
        {
            return func(s1, s2, n - 1, m - 1, count + 1);
        }
        else
        {
            return max(func(s1, s2, n, m - 1, 0), func(s1, s2, n - 1, m, 0));
        }
    }

    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int count = 0;
        return func(S1, S2, n, m, count);
    }
};


// TABULATION
// TC = O(M * N), SC = O(M * N)

class Solution
{
public:
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 0;
        }

        for (int j = 0; j < m + 1; j++)
        {
            dp[0][j] = 0;
        }

        int count = 0;

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < m + 1; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    count = max(count, dp[i][j]);
                }
                else
                {
                    dp[i][j] = 0;
                }
            }
        }
        return count;
    }
};
