// Problem Link: https://leetcode.com/problems/dungeon-game/

1) RECURSIVE
Gives TLE
41 / 45 test cases passed with this solution

class Solution {
public:
    int solve(int i, int j, int m , int n, vector<vector<int>> &grid)
    {
        // if we come out of the grid simply return a large value
        if(i >= m || j >= n)
            return INT_MAX;
        
        // calucate health by the 2 possible ways
        int down = solve(i + 1, j, m, n, grid);
        int right = solve(i, j + 1, m, n, grid);
        
		// take the min both both
        int health = min(down, right);
        
        // we reach the destination when both the sides return INT_MAX
        if(health == INT_MAX)
        {
            health = 1; // both are +ve large integers so min health required = 1
        }
        
        int ans = 0;
        if(health - grid[i][j] > 0)
        {
            ans = health - grid[i][j];
        }
        else
        {
            ans = 1;
        }
             
        return ans;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        return solve(0, 0, m, n, dungeon);
    }
};


2) MEMOIZATION
ALL TEST CASES PASSED! 🥳

class Solution {
public:
    int solve(int i, int j, int m , int n, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        // if we come out of the grid simply return a large value
        if(i >= m || j >= n)
            return INT_MAX;
        
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        
        // calucate health by the 2 possible ways
        int down = solve(i + 1, j, m, n, grid, dp);
        int right = solve(i, j + 1, m, n, grid, dp);
        
        int health = min(down, right);
        
        // we reach the destination when both the sides return INT_MAX
        if(health == INT_MAX)
        {
            health = 1; // both are +ve large integers so min health required = 1
        }
        
        int ans = 0;
        if(health - grid[i][j] > 0)
        {
            ans = health - grid[i][j];
        }
        else
        {
            ans = 1;
        }
             
        return dp[i][j] = ans;
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, INT_MAX));
        
        return solve(0, 0, m, n, dungeon, dp);
    }
};


3) TABULATION
ALL TEST CASES PASSED! 🥳

class Solution {
public:    
    int calculateMinimumHP(vector<vector<int>>& dungeon) 
    {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, INT_MAX));
        
        for(int i = m - 1; i >= 0; i--)
        {
            for(int j = n - 1; j >= 0; j--)
            {
                int right = dp[i + 1][j];
                int down = dp[i][j + 1];
                
                int health = min(down, right);
                
                // we reach the destination when both the sides return INT_MAX
                if(health == INT_MAX)
                {
                    health = 1; // both are +ve large integers so min health required = 1
                }
                
                int ans = 0;
                if(health - dungeon[i][j] > 0)
                {
                    ans = health - dungeon[i][j];
                }
                else
                {
                    ans = 1;
                }
             
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};
