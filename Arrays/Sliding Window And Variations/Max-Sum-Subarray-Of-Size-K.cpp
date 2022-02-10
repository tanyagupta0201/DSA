// Problem Link: https://practice.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1

class Solution
{
public:
    int maximumSumSubarray(int K, vector<int> &arr, int n)
    {
        int i = 0, j = 0;
        int sum = 0;
        int maxi = INT_MIN;

        while (j < n)
        {
            sum += arr[j];

            if (j - i + 1 == K)
            {
                maxi = max(maxi, sum);
                sum = sum - arr[i];
                i++;
            }

            j++;
        }

        return maxi;
    }
};
