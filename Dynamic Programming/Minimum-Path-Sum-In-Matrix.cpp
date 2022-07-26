// Problem Link: https://leetcode.com/problems/minimum-path-sum/


1) RECURSION
   This solution will give TLE (ONLY 23 / 61 TEST CASES PASSED)

class Solution {
public:
    long long int solve(int i, int j, vector<vector<int>> &grid)
    {
        if(i == 0 && j == 0)
            return grid[0][0];
        
		// Out of bounds case
		// Add a large value so that this path is not taken into consideration
        if(i < 0 || j < 0)
            return INT_MAX;
        
        long long int up = grid[i][j] + solve(i - 1, j, grid);
        long long int left = grid[i][j] + solve(i, j - 1, grid);
        
        return min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        return solve(m - 1, n - 1, grid);
    }
};



2) MEMOIZATION
   This solution passes all the test cases

class Solution {
public:
    long long int solve(int i, int j, vector<vector<int>> &grid, vector<vector<long long int>> &dp)
    {
        if(i == 0 && j == 0)
            return grid[0][0];
        
		// Out of bounds case
		// Add a large value so that this path is not taken into consideration
        if(i < 0 || j < 0)
            return INT_MAX;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        long long int up = grid[i][j] + solve(i - 1, j, grid, dp);
        long long int left = grid[i][j] + solve(i, j - 1, grid, dp);
        
        return dp[i][j] = min(up, left);
    }
    
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<long long int>> dp(m, vector<long long int> (n, -1));
        
        return solve(m - 1, n - 1, grid, dp);
    }
};



3) TABULATION
This solution passes all the test cases

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<long long int>> dp(m, vector<long long int> (n, 0));
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0)
                {
                    dp[i][j] = grid[0][0];
                }
                else
                {
                    long long int up = grid[i][j];
                    if(i > 0)
                        up += dp[i - 1][j];
                    else
                        up += 1e9; // to neglect this path  
                    
                    long long int left = grid[i][j];                    
                    if(j > 0)
                        left += dp[i][j - 1];
                    else
                        left += 1e9; // to neglect this path
                    
                    dp[i][j] = min(left, up);
                }
            }
        }
        
        return dp[m - 1][n - 1];
    }
};
