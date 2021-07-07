#include <bits/stdc++.h>
using namespace std;

int largest(int arr[], int n)
{
    int maxi = -10000;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

int main()
{
    int arr[1000];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    printf("%d ", largest(arr, n));
    return 0;
}
