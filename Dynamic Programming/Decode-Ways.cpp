// https://leetcode.com/problems/decode-ways/

// RECURSIVE

class Solution {
public:
    int f(int i, string s)
    {
        // last char is decoded if it exceeds the size
        if(i > s.size())
           return 1;
        
        // zero cannot be decoded
        else if(s[i] == '0')
            return 0;
        
        // last char can be decoded only in one way
        else if(i == s.size() - 1)
            return 1;
        
        // There are 2 options 
        // either take 1 char or 2 char
        else if(s[i] == '1' || s[i] == '2' && s[i + 1] >= 48 && s[i + 1] <= 54)
            return f(i + 1, s) + f(i + 2, s);
        
        // only char can be decoded
        else
            return f(i + 1, s);
    }
    
    int numDecodings(string s)
    {
        return f(0, s);        
    }
};


// MEMOIZATION
// TC = O(N), SC = O(N)

class Solution {
public:
    int f(int i, string s, vector<int> &dp)
    {
        // last char is decoded if it exceeds the size
        if(i > s.size())
           return 1;
        
        // zero cannot be decoded
        else if(s[i] == '0')
            return 0;
        
        // last char can be decoded only in one way
        else if(i == s.size() - 1)
            return 1;
        
        else if(dp[i] != -1)
            return dp[i];
        
        // There are 2 options 
        // either take 1 char or 2 char
        else if(s[i] == '1' || s[i] == '2' && s[i + 1] >= 48 && s[i + 1] <= 54)
            return dp[i] = f(i + 1, s, dp) + f(i + 2, s, dp);
        
        // only char can be decoded
        else
            return dp[i] = f(i + 1, s, dp);
    }
    
    int numDecodings(string s)
    {
        vector<int> dp(s.size() + 1, -1);
        return f(0, s, dp);        
    }
};

