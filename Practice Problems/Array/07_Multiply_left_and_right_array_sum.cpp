/*
    The task is to divide a array into two sub array (left and right) containing n/2 elements each and do the sum of the subarrays and then multiply both the subarrays.

    arr[ ] = {1, 2, 3, 4}
    Output : 21
    
    Explanation:
    Sum up an array from index 0 to 1 = 3
    Sum up an array from index 2 to 3 = 7
    Their multiplication is 21

*/

#include <bits/stdc++.h>
using namespace std;

int multiply(int arr[], int n)
{
    // Complete the function
    int s1 = 0, s2 = 0;

    for (int i = 0; i < n / 2; i++)
    {
        s1 += arr[i];
    }

    for (int i = n / 2; i < n; i++)
    {
        s2 += arr[i];
    }

    return s1 * s2;
}

int main()
{
    int n;
    cin >> n;
    int a[10000];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << multiply(a, n);

    return 0;
}