// https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

class Solution{
	public:
	
	int LCS(string s1, string s2, int n1, int n2)
	{
	    vector<vector<int>> dp(n1 + 1, vector<int> (n2 + 1, 0));
	    
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
	            if(s1[i - 1] == s2[j - 1])
	            {
	                dp[i][j] = 1 + dp[i - 1][j - 1];
	            }
	            else
	            {
	                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	            }
	        }
	    }
	    return dp[n1][n2];
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n1 = str1.length();
	    int n2 = str2.length();
	    
	    int len = LCS(str1, str2, n1, n2);
	    
	    // deletions = n2 - len(LCS)
	    // insertions = n1 - Len(LCS)
	    // Total = n1 + n2 - 2 * len(LCS)
	    
	    return n1 + n2 - (len * 2);
	} 
};

