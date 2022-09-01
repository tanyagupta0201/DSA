// https://leetcode.com/problems/longest-palindromic-subsequence/

// MEMOIZATION
class Solution {
public:
    // We need to find Longest palidromic subseq
    // Just reverse the string and compare the reversed and the original string
    // Then find LCS
    int LCS(string s1, string s2, int n1, int n2, vector<vector<int>> &dp)
    {
        if(n1 == 0 || n2 == 0)
            return 0;
        
        if(dp[n1][n2] != -1)
            return dp[n1][n2];
        
        if(s1[n1 - 1] == s2[n2 - 1])
        {
            return dp[n1][n2] = 1 + LCS(s1, s2, n1 - 1, n2 - 1, dp);
        }
        else
        {
            return dp[n1][n2] = max(LCS(s1, s2, n1 - 1, n2, dp), LCS(s1, s2, n1, n2 - 1, dp));
        }
    }
    
    int longestPalindromeSubseq(string s) 
    {
        string s1 = s;
        reverse(s.begin(), s.end());
        int n = s.length();
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return LCS(s1, s, n, n, dp);
    }
};



// TABULATION

class Solution {
public:    
    int longestPalindromeSubseq(string s) 
    {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s.length();
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        
        for(int i = 0; i < n; i++)
            dp[i][0] = 0;
        
        for(int j = 0; j < n; j++)
            dp[0][j] = 0;
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < n + 1; j++)
            {
                if(s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};
