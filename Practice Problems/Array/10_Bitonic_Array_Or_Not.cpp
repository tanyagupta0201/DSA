// Bitonic Array is an array which is first strictly increasing and then strictly decreasing

#include <bits/stdc++.h>
using namespace std;

int IsBitonic(int a[], int n)
{
    int i, j;

    for (i = 1; i < n; i++)
    {
        if (a[i] > a[i - 1])
        {
            continue;
        }
        if (a[i] <= a[i - 1])
        {
            break;
        }
    }

    if (i == n)
    {
        return 1;
    }

    for (j = i + 1; j < n; j++)
    {
        if (a[j] < a[j - 1])
        {
            continue;
        }
        if (a[j] >= a[j - 1])
        {
            break;
        }
    }

    if (j == n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    (IsBitonic(a, n) == 1) ? cout << "Yes, it is Bitonic Array !!" : cout << "No, it is not a Bitonic Array !!";
    return 0;
}