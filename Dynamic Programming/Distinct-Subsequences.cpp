// https://leetcode.com/problems/distinct-subsequences/

// RECURSIVE
// TC = EXPONENTIAL, SC = O(N + M)
class Solution {
public:
    int count(int n, int m, string s, string t)
    {
        // if str2 is exhausted then we have got a subsequence
        if(m == 0)
            return 1;
        
        // if str1 is exhausted and str1 is not exhausted then we cannot get any subsequence
        if(n == 0)
            return 0;
        
        // if the length of str1 becomes less than length of str2, then we cant have any subsequence
        if(n < m)
            return 0;
        
        // if the character of both the strings matches, then we have 2 ways
        if(s[n - 1] == t[m - 1])
        {
            // we want the curr character of str1 + we dont want the curr character of str1
            return count(n - 1, m - 1, s, t) + count(n - 1, m, s, t);
        }
        else
        {
            // decrease the the index of str1 by 1
            return count(n - 1, m, s, t);
        }
    }
    
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        
        return count(n, m, s, t);
    }
};


// MEMOIZATION
// TC = O(N * M), SC = O(N * M) + O(N + M)

class Solution {
public:
    int count(int n, int m, string s, string t, vector<vector<int>> &dp)
    {
        // if str2 is exhausted then we have got a subsequence
        if(m == 0)
            return 1;
        
        // if str1 is exhausted and str1 is not exhausted then we cannot get any subsequence
        if(n == 0)
            return 0;
        
        // if the length of str1 becomes less than length of str2, then we cant have any subsequence
        if(n < m)
            return 0;
        
        if(dp[n][m] != -1)
            return dp[n][m];
        
        // if the character of both the strings matches, then we have 2 ways
        if(s[n - 1] == t[m - 1])
        {
            // we want the curr character of str1 + we dont want the curr character of str1
            return dp[n][m] = count(n - 1, m - 1, s, t, dp) + count(n - 1, m, s, t, dp);
        }
        else
        {
            // decrease the the index of str1 by 1
            return dp[n][m] = count(n - 1, m, s, t, dp);
        }
    }
    
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return count(n, m, s, t, dp);
    }
};

// TABULATION
// TC = O(N * M), SC = O(N * M) 

class Solution {
public:   
    int numDistinct(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        
        vector<vector<double>> dp(n + 1, vector<double> (m + 1, 0)); // double is taken due to Leetcode constraints
        
        for(int i = 0; i < n + 1; i++)
        {
            dp[i][0] = 1;
        }
        
       // for(int j = 1; j < m + 1; j++)
        //{
          //  dp[0][j] = 0;
        //}
        
        for(int i = 1; i < n + 1; i++)
        {
            for(int j = 1; j < m + 1; j++)
            {
                // if the character of both the strings matches, then we have 2 ways
                if(s[i - 1] == t[j - 1])
                {
                    // we want the curr character of str1 + we dont want the curr character of str1
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    // decrease the the index of str1 by 1
                   dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};
