// Problem Link: https://www.interviewbit.com/problems/min-sum-path-in-triangle/


// RECURSIVE
int solve(int i, int j, int m, vector<vector<int>> &A)
{
    if (i == m - 1)
        return A[m - 1][j];

    int down = A[i][j] + solve(i + 1, j, m, A);
    int diagonal = A[i][j] + solve(i + 1, j + 1, m, A);

    return min(down, diagonal);
}

int Solution::minimumTotal(vector<vector<int>> &A)
{
    int m = A.size(); // number of rows

    return solve(0, 0, m, A);
}


// MEMOIZATION
int solve(int i, int j, int m, vector<vector<int>> &A, vector<vector<int>> &dp)
{
    if (i == m - 1)
        return A[m - 1][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = A[i][j] + solve(i + 1, j, m, A, dp);
    int diagonal = A[i][j] + solve(i + 1, j + 1, m, A, dp);

    return dp[i][j] = min(down, diagonal);
}

int Solution::minimumTotal(vector<vector<int>> &A)
{

    int m = A.size();
    vector<vector<int>> dp(m, vector<int>(m + 1, -1));

    return solve(0, 0, m, A, dp);
}


// TABULATION
int Solution::minimumTotal(vector<vector<int>> &A)
{
    int m = A.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));

    // Base Case
    for (int j = 0; j < m; j++)
    {
        dp[m - 1][j] = A[m - 1][j];
    }

    for (int i = m - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = A[i][j] + dp[i + 1][j];
            int diagonal = A[i][j] + dp[i + 1][j + 1];

            dp[i][j] = min(down, diagonal);
        }
    }

    return dp[0][0];
}
