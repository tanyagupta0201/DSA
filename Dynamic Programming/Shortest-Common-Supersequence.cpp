// https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        int n1 = str1.length();
        int n2 = str2.length();
        
        vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
        
        // Find length of LCS
        for(int i = 0; i < n1 + 1; i++)
        {
            dp[i][0] = 0;    
        }
        
        for(int j = 0; j < n2 + 1; j++)
        {
            dp[0][j] = 0;
        }
        
        for(int i = 1; i < n1 + 1; i++)
        {
            for(int j = 1; j < n2 + 1; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        string ans = "";
        int i = n1, j = n2; // we would be traversing from the bottom
        
        while(i > 0 && j > 0)
        {
            // if both the characters are equal then add that character once
            // decrease both i and j and we move to prev diagonal
            if(str1[i - 1] == str2[j - 1])
            {
                ans += str1[i - 1];
                i--;
                j--;
            }
            // we would move to the one which is bigger
            else if(dp[i - 1][j] > dp[i][j - 1])
            {
                // we would add the one whose index we are decreasing
                ans += str1[i - 1];
                i--;
            }
            else
            {
                ans += str2[j - 1];
                j--;
            }
        }
        
        // if str2 finishes but str1 does not
        while(i > 0)
        {
            ans += str1[i - 1];
            i--;
        }
        
        // if str1 finishes but str2 does not
        while(j > 0)
        {
            ans += str2[j - 1];
            j--;
        }
        
        // need to reverse the string because we moved from bottom to up
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
