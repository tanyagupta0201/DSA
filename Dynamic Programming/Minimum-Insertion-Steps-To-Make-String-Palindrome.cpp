// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:
    // Just keep the palidromic string that is available constant
    // the characters which cause problem we need to attach them to the string in reverse order
    // we find the length of longest palindromic subsequence 
    // then subtract it from the length of the original string
    // only that may insertions will be needed
    
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
    
    int minInsertions(string s) 
    {
        int n = s.length();
        int len = longestPalindromeSubseq(s);  
        
        return n - len;        
    }
};
