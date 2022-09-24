// https://leetcode.com/problems/wildcard-matching/


// RECURSIVE 
// TC = Exponential, SC = O(N1 + N2)

class Solution {
public:
    bool f(int i, int j, string p, string s)
    {
        // if both the strings are exhausted, return true
        if(i == 0 && j == 0)
            return true;
        
        // str1 is exhausted and str2 is not exhausted, then return false
        if(i == 0 && j > 0)
            return false;
        
        // str1 is not exhausted and str2 is exhausted, then all the remaining characters of str1 should be * otherwise the strings would not match
        if(i > 0 && j == 0)
        {
            for(int k = 1; k <= i; k++)
            {
                if(p[k - 1] != '*')
                    return false;
            }
            
            // if all the remaining characters of str1 are *     
            return true;
        }
        
        // shrink both the strings in case of match
        if(p[i - 1] == s[j - 1] || p[i - 1] == '?')
            return f(i - 1, j - 1, p, s);
        
        // 2 Choices
        // we can match the star with a char or we cannot match
        // in case of matching stay at the same index of star
        if(p[i - 1] == '*')
            return f(i, j - 1, p, s) || f(i - 1, j, p, s);
        
        // if none of the case is found, we cannot match the strings 
        return false;
    }
    
    bool isMatch(string s, string p)
    {
        int n1 = p.size();
        int n2 = s.size();
        
        // we are following 1 based indexing
        return f(n1, n2, p, s);
    }
};



// MEMOIZATION
// TC = O(N1 * N2), SC = O(N1 * N2) + O(N1 + N2)

class Solution {
public:
    bool f(int i, int j, string p, string s, vector<vector<int>> &dp)
    {
        // if both the strings are exhausted, return true
        if(i == 0 && j == 0)
            return true;
        
        // str1 is exhausted and str2 is not exhausted, then return false
        if(i == 0 && j > 0)
            return false;
        
        // str1 is not exhausted and str2 is exhausted, then all the remaining characters of str1 should be * otherwise the strings would not match
        if(i > 0 && j == 0)
        {
            for(int k = 1; k <= i; k++)
            {
                if(p[k - 1] != '*')
                    return false;
            }
            
            // if all the remaining characters of str1 are *     
            return true;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // shrink both the strings in case of match
        if(p[i - 1] == s[j - 1] || p[i - 1] == '?')
            return dp[i][j] = f(i - 1, j - 1, p, s, dp);
        
        // 2 Choices
        // we can match the star with a char or we cannot match
        // in case of matching stay at the same index of star
        if(p[i - 1] == '*')
            return dp[i][j] = f(i, j - 1, p, s, dp) || f(i - 1, j, p, s, dp);
        
        // if none of the case is found, we cannot match the strings 
        return dp[i][j] = false;
    }
    
    bool isMatch(string s, string p)
    {
        int n1 = p.size();
        int n2 = s.size();
        
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, -1));
        
        // we are following 1 based indexing
        return f(n1, n2, p, s, dp);
    }
};


// TABULATION
// TC = O(N1 * N2), SC = O(N1 * N2)

class Solution {
public:    
    bool isMatch(string s, string p)
    {
        int n1 = p.size();
        int n2 = s.size();
        
        vector<vector<bool>> dp(n1 + 1, vector<bool> (n2 + 1, false));
        
        // base case 1
        dp[0][0] = true;
        
        // base case 2
        // for any value of j, i is 0
        for(int j = 1; j < n2 + 1; j++)
            dp[0][j] = false;
    
        // base case 3
        for(int i = 1; i < n1 + 1; i++)
        {
            bool flag = true;
            
            for(int k = 1; k <= i; k++)
            {
                if(p[k - 1] != '*')
                {
                    flag = false;
                    break;
                }
            }
            
            dp[i][0] = flag;
        }
        
        for(int i = 1; i < n1 + 1; i++)
        {
            for(int j = 1; j < n2 + 1; j++)
            {
                if(p[i - 1] == s[j - 1] || p[i - 1] == '?')
                   dp[i][j] = dp[i - 1][j - 1];
        
                else if(p[i - 1] == '*')
                   dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
        
                // if none of the case is found, we cannot match the strings 
                else dp[i][j] = false;
            }
        }
        
        return dp[n1][n2];
    }
};


