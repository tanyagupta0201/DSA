// Given an array. Find the pair of elements that sum to k(given).
// Example: a[] = {1,3,5,7,10,11,12,13} and k = 16
// The pairs are: 3 and 13, 5 and 11

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, a[50], currSum = 0;
    cout << "Enter the value of k: ";
    cin >> k;
    cout << endl;
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int i = 0;
    int j = n - 1;

    while (i < j)
    {
        currSum = a[i] + a[j];
        if (currSum > k)
        {
            j--;
        }
        else if (currSum < k)
        {
            i++;
        }
        else if (currSum == k)
        {
            cout << a[i] << " and " << a[j] << endl;
            i++;
            j--;
        }
    }
    return 0;
}