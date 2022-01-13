// Problem Link: https://leetcode.com/problems/subsets/

class Solution
{
public:
    void AllSubsets(int i, vector<int> &nums, int n, vector<int> output, vector<vector<int>> &final)
    {
        // Base Condition
        if (i == n)
        {
            final.push_back(output);
            return;
        }

        // Excluding the current number
        AllSubsets(i + 1, nums, n, output, final);

        // Including the current number
        output.push_back(nums[i]);
        AllSubsets(i + 1, nums, n, output, final);
    }

    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<int> output;
        vector<vector<int>> final;

        AllSubsets(0, nums, nums.size(), output, final);
        return final;
    }
};