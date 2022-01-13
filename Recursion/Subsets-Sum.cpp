// Problem Link: https://practice.geeksforgeeks.org/problems/subset-sums2234/1#

class Solution
{
public:
    void SubsetSum(int i, int sum, vector<int> &arr, int n, vector<int> &v)
    {
        // Base Case
        if (i == n)
        {
            v.push_back(sum);
            return;
        }

        // Exclude the current number
        SubsetSum(i + 1, sum, arr, n, v);

        // Include the current number
        SubsetSum(i + 1, sum + arr[i], arr, n, v);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> v;
        SubsetSum(0, 0, arr, N, v);
        sort(v.begin(), v.end());
        return v;
    }
};