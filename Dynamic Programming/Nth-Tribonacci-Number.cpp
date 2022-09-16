// https://leetcode.com/problems/n-th-tribonacci-number/

// RECURSIVE

class Solution {
public:
    int tribonacci(int n) 
    {
        if(n == 0)
            return 0;
        
        if(n == 1 || n == 2)
            return 1;
        
        return tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);        
    }
};


// MEMOIZATION

class Solution {
public:
    int f(int n, vector<int> &dp) 
    {
        if(n == 0)
            return 0;
        
        if(n == 1 || n == 2)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = f(n - 1, dp) + f(n - 2, dp) + f(n - 3, dp);        
    }
    
    int tribonacci(int n) 
    {
        vector<int> dp(n + 1, -1);
        
        return f(n, dp);        
    }
};


// TABULATION

class Solution {
public:
    int tribonacci(int n) 
    {
        vector<int> dp(n + 1, 0);
        
        if(n == 0)
            return 0;
        
        if(n == 1)
            return 1;
        
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        
        for(int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];            
        }
        
        return dp[n];      
    }
};


