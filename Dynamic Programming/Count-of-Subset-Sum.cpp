// Count of Subset Sum Problem: https://practice.geeksforgeeks.org/problems/perfect-sum-problem5633/1

#include <bits/stdc++.h>
using namespace std;

int CountSubsetSum(int arr[], int n, int sum)
{
    // DP Matrix
    int t[n + 1][sum + 1];

    // Initialization
    // Base Case
    for (int i = 0; i < sum + 1; i++)
    {
        t[0][i] = 0;
    }

    for (int i = 0; i < n + 1; i++)
    {
        t[i][0] = 1;
    }

    // DP
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {
            if (arr[i - 1] <= j)
            {
                // Number is either taken or not taken
                t[i][j] = t[i - 1][j - arr[i - 1]] + t[i - 1][j];
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

int main()
{
    int sum;
    cin >> sum;

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << CountSubsetSum(arr, n, sum);
    return 0;
}