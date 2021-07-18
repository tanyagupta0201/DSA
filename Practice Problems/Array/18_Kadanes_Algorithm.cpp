#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, currSum = 0, maxSum = 0;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[50];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    //Kadane's Algorithm for Maximum Subarray Sum
    for (int i = 0; i < n; i++)
    {
        currSum += a[i];
        if (currSum < 0)
        {
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }

    cout << "Maximum Sum: " << maxSum;
    return 0;
}