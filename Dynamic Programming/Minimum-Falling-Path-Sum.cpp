// Problem Link: https://leetcode.com/problems/minimum-falling-path-sum/

1) RECURSIVE
GIVES TLE (38 / 49 test cases passed)

Time Complexity = would be in exponential (3^n)
Space Complexity = O(n) (Recursion stack)

class Solution {
public:
    long long int solve(int i, int j, vector<vector<int>> &matrix)
    {
        if(j < 0 || j > matrix[0].size() - 1)
            return INT_MAX;
        
        if(i == 0)
            return matrix[0][j];
        
        long long int up = matrix[i][j] + solve(i - 1, j, matrix);
        long long int right_diagonal = matrix[i][j] + solve(i - 1, j + 1, matrix);
        long long int left_diagonal = matrix[i][j] + solve(i - 1, j - 1, matrix);
        
        return min(up, min(right_diagonal, left_diagonal));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        long long int mini = INT_MAX;
        
        for(int j = 0; j < m; j++)
        {
            mini = min(mini, solve(n - 1, j, matrix));
        }
        
        return mini;
    }
};


2) MEMOIZATION
ALL TEST CASES PASSED!

Time Complexity = O(n * m)
Space Complexity = O(n * m) + O(n) (DP array + Recursion stack)

class Solution {
public:
    long long int solve(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
    {
        if(j < 0 || j > matrix[0].size() - 1)
            return INT_MAX;
        
        if(i == 0)
            return matrix[0][j];
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        long long int up = matrix[i][j] + solve(i - 1, j, matrix, dp);
        long long int right_diagonal = matrix[i][j] + solve(i - 1, j + 1, matrix, dp);
        long long int left_diagonal = matrix[i][j] + solve(i - 1, j - 1, matrix, dp);
        
        return dp[i][j] = min(up, min(right_diagonal, left_diagonal));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int> (n, -1));
        
        long long int mini = INT_MAX;
        
        for(int j = 0; j < m; j++)
        {
            mini = min(mini, solve(n - 1, j, matrix, dp));
        }
        
        return mini;
    }
};


3) TABULATION
ALL TEST CASES PASSED!

Time Complexity = O(n * m)
Space Complexity = O(n * m) (DP array)

  class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<long long int>> dp(m, vector<long long int> (n, -1));
        
        // Base Case
        for(int j = 0; j < n; j++)
        {
            dp[0][j] = matrix[0][j];
        }
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                long long int up = matrix[i][j] + dp[i - 1] [j];
                
                long long int right_diagonal = matrix[i][j];
                
                if(j + 1 < m)
                    right_diagonal += dp[i - 1] [j + 1];
                else
                    right_diagonal += INT_MAX;
                
                long long int left_diagonal = matrix[i][j];
                if(j - 1 >= 0)
                   left_diagonal += dp[i - 1][j - 1];
                else
                   left_diagonal += INT_MAX;
        
                dp[i][j] = min(up, min(right_diagonal, left_diagonal));
            }
        }
        
        long long int mini = INT_MAX;
        
        for(int j = 0; j < m; j++)
        {
            mini = min(mini, dp[n - 1][j]);
        }
        
        return mini;
    }
};
