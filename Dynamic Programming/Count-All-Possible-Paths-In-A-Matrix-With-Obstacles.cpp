// Problem Link: https://www.interviewbit.com/problems/unique-paths-in-a-grid/

// Recursive
int countPaths(int i, int j, vector<vector<int>> &grid)
{
    if (i >= 0 && j >= 0 && grid[i][j] == 1)
        return 0;

    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    int up = countPaths(i - 1, j, grid);
    int left = countPaths(i, j - 1, grid);

    return up + left;
}

int Solution::uniquePathsWithObstacles(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();

    return countPaths(m - 1, n - 1, A);
}

// Memoization
int countPaths(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && grid[i][j] == 1)
        return 0;

    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = countPaths(i - 1, j, grid, dp);
    int left = countPaths(i, j - 1, grid, dp);

    return dp[i][j] = up + left;
}

int Solution::uniquePathsWithObstacles(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();

    vector<vector<int>> dp(m, vector<int>(n, -1));
    return countPaths(m - 1, n - 1, A, dp);
}

// Tabulation
int Solution::uniquePathsWithObstacles(vector<vector<int>> &A)
{
    int m = A.size();
    int n = A[0].size();

    int dp[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // if there is an obstacle
            if (A[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else if (i == 0 && j == 0)
            {
                dp[i][j] = 1;
            }
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];

                if (j > 0)
                    left = dp[i][j - 1];

                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}
