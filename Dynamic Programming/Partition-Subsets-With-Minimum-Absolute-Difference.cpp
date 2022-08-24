// https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

// Positive numbers only
#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
	int minDifference(int arr[], int n)  
	{ 
	    int totalSum = 0;
	    for(int i = 0; i < n; i++)
	    {
	        totalSum += arr[i];
	    }
	    
	    int k = totalSum;
	    
	    // Answer will lie in the range 0 to totalSum
	    // Fill the matrix by tabulation and check which are all the valid S1
	    vector<vector<bool>> dp(n, vector<bool> (k + 1, 0));
	    
	    for(int i = 0; i < n; i++)
	    {
	        dp[i][0] = true;
	    }
	    
	    if(arr[0] <= k)
	    {
	        dp[0][arr[0]] = true;
	    }
	    
	    for(int idx = 1; idx < n; idx++)
	    {
	        for(int target = 1; target < k + 1; target++)
	        {
	            bool notTake = dp[idx - 1][target];
	            
	            bool take = false;
	            if(arr[idx] <= target)
	            {
	                take = dp[idx - 1][target - arr[idx]];
	            }
	            
	            dp[idx][target] = take or notTake;
	        }
	    }
	    
	    int mini = INT_MAX;
	    for(int s1 = 0; s1 <= totalSum / 2; s1++) // traversing only half because the values will start repeating in reverse order
	    {
	        if(dp[n - 1][s1] == true)
	        {
	            int s2 = totalSum - s1;
	            mini = min(mini, abs(s1 - s2));
	        }
	    }
	    
	    return mini;
	} 
};


