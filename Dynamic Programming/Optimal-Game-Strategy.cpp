// TC = SC = O(N * N)

/*
    1) if the user chooses ith coin, the opponent can choose from i+1th or jth coin. if he chooses i+1th coin,
    user is left with [i+2,j] range. if opp chooses jth coin, then user is left with [i+1,j-1] range to choose from.
    Also opponent tries to choose in such a way that the user has minimum value left.
    
    int p1 = arr[i] + min(solve(i + 2, j), solve(i + 1, j - 1));
 
    2) if user chooses jth coin, opponent can choose ith coin or j-1th coin. if opp chooses ith coin, user can
       choose in range [i+1,j-1]. if opp chooses j-1th coin, user can choose in range [i,j-2].
       
    int p2 = arr[j] + min(solve(i + 1, j - 1), solve(i, j - 2));

*/

class Solution {
public:
    // 1 5 233 7
    int solve(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(i > j)
          return 0;

        if(dp[i][j] != -1)
           return dp[i][j];

        int p1 = nums[i] + min( solve(i + 2, j, nums, dp) , solve(i + 1, j - 1, nums, dp) );

        int p2 = nums[j] + min( solve(i + 1, j - 1, nums, dp) , solve(i, j - 2, nums, dp));

        return dp[i][j] = max(p1, p2);
    }

    bool PredictTheWinner(vector<int>& nums) 
    {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));

        int total = 0;
        for(int i = 0; i < n; i++)
           total += nums[i];

        int player1 = solve(0, n - 1, nums, dp); // gives max coins for player 1
        int player2 = total - player1; // this is how you can calculate for player 2

        if(player1 >= player2)
           return true;
        return false;
    }
};
