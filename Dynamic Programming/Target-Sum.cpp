// https://leetcode.com/problems/target-sum/

// We can divide the + and - signs into two subsequences then the problem reduces to S1 - S2 = Target/Diff 


// Recursive

class Solution {
public:
    int findWays(int idx, vector<int> &nums, int sum)
    {
        //vector<vector<int>> dp(n, vector<int>(sum + 1, 0));        
        if(idx == 0)
        {
            if(sum == 0 && nums[0] == 0)
                return 2;
            
            if(sum == 0 || sum == nums[0])
                return 1;
            
            return 0;
        }
        
        int notTake = findWays(idx - 1, nums, sum);
        
        int Take = 0;
        if(nums[idx] <= sum)
            Take = findWays(idx - 1, nums, sum - nums[idx]); 
        
        return Take + notTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++)
            totalSum += nums[i];
        
        int s1 = (totalSum + target) / 2; // new target
        
        if((totalSum + target) % 2 != 0 || (totalSum + target) < 0)
            return 0;
        
        return findWays(n - 1, nums, s1);    
    }
};


// MEMOIZATION

class Solution {
public:
    int findWays(int idx, vector<int> &nums, int sum, vector<vector<int>> &dp)
    {       
        if(idx == 0)
        {
            if(sum == 0 && nums[0] == 0)
                return 2;
            
            if(sum == 0 || sum == nums[0])
                return 1;
            
            return 0;
        }
        
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
        
        int notTake = findWays(idx - 1, nums, sum, dp);
        
        int Take = 0;
        if(nums[idx] <= sum)
            Take = findWays(idx - 1, nums, sum - nums[idx], dp); 
        
        return dp[idx][sum] = Take + notTake;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) 
    {
        int n = nums.size();
        
        int totalSum = 0;
        for(int i = 0; i < nums.size(); i++)
            totalSum += nums[i];
        
        int s1 = (totalSum + target) / 2; // new target
        
        if((totalSum + target) % 2 != 0 || (totalSum + target) < 0)
            return 0;
        
        vector<vector<int>> dp(n, vector<int>(s1 + 1, -1));        
        
        return findWays(n - 1, nums, s1, dp);    
    }
};
