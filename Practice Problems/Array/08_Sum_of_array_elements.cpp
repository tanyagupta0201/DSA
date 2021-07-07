// Find the sum of all the array elements

#include <bits/stdc++.h>
using namespace std;

int sumElement(int arr[], int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    return sum;
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

    cout << sumElement(a, n);
    return 0;
}