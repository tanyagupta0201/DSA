// Equal Sum Partition: https://leetcode.com/problems/partition-equal-subset-sum/

#include <bits/stdc++.h>
using namespace std;

bool subsetSum(int arr[], int n, int sum)
{
    // DP Matrix
    bool t[n + 1][sum + 1];

    // Initialization
    // Base Case
    for (int i = 0; i < sum + 1; i++)
    {
        t[0][i] = false;
    }

    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = true;
    }

    // DP
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                // Number is either taken or not taken
                t[i][j] = (t[i - 1][j - arr[i - 1]]) || t[i - 1][j];
            }
            else
            {
                // Number is not taken
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum];
}

bool EqualSumPartition(int arr[], int n)
{
    int sum = 0;

    // Calculating the sum of all the elements of the array
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    if (sum % 2 != 0)
    {
        // If the sum is odd then equal sum partition is not possible
        return false;
    }
    else
    {
        // If the sum is even then divide the sum by 2 and apply suset sum problem approach
        return subsetSum(arr, n, sum / 2);
    }
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << EqualSumPartition(arr, n) << endl;

    return 0;
}