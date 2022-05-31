class Solution
{
public:
    int dp[1001][1001];

    int LCS(string text1, string text2, int n1, int n2)
    {
        if (n1 == 0 || n2 == 0)
            return 0;

        for (int i = 0; i < n1 + 1; i++)
        {
            for (int j = 0; j < n2 + 1; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
            }
        }

        for (int i = 1; i < n1 + 1; i++)
        {
            for (int j = 1; j < n2 + 1; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                {
                    // Decrease the length of both the strings
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    // We have choice, either decrease the length of str1 or str1
                    // Take the string which returns the max one
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[n1][n2];
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();

        memset(dp, -1, sizeof(dp));

        return LCS(text1, text2, n1, n2);
    }
};