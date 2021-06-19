#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, currSum = 0, maxSum = 0, left = -1, right = -1;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[50];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            currSum = 0;
            for (int k = i; k <= j; k++)
            {
                currSum += a[k];
            }

            //Update the maxSum if currSum is greater than maxSum
            if (currSum > maxSum)
            {
                maxSum = currSum;
                left = i;
                right = j;
            }
        }
    }

    //Print the maximum sum
    cout << "Maximum Subarray sum is: " << maxSum << endl;

    //Print the subarray which has the largest sum
    for (int k = left; k <= right; k++)
    {
        cout << a[k] << " ";
    }

    return 0;
}