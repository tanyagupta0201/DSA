/*
    Given an array, rotate the array by one position in clock-wise direction.

    Example:
    Input:
    N = 5
    A[] = {1, 2, 3, 4, 5}

    Output:
    5 1 2 3 4
*/

#include <bits/stdc++.h>
using namespace std;

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void rotate(int a[], int n)
{
    int temp = a[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        a[i] = a[i - 1];
    }
    a[0] = temp;
}

int main()
{
    int a[] = {1, 6, 8, 9, 11};
    int n = sizeof(a) / sizeof(int);

    rotate(a, n);
    display(a, n);
    return 0;
}