// https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1/

class Solution
{
public:
    int lenOfLongSubarr(int A[], int N, int K)
    {
        unordered_map<int, int> m;

        int sum = 0, maxLen = 0;

        for (int i = 0; i < N; i++)
        {
            sum += A[i];

            // Update the length when sum becomes equal to K for the first time
            if (sum == K)
            {
                maxLen = i + 1;
            }

            // When sum is not present in the map, make an entry for it in the hash map
            if (m.find(sum) == m.end())
            {
                m[sum] = i;
            }

            // check if 'sum - K' is present in 'm' or not
            if (m.find(sum - K) != m.end())
            {
                // update maxLength
                if (maxLen < (i - m[sum - K]))
                    maxLen = i - m[sum - K];
            }
        }
        return maxLen;
    }
};