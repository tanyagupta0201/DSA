/*
    Rotate the array by d elements.

    Input: 
    a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    d = 3

    Output:
    a[] = {4, 5, 6, 7, 8, 9, 10, 1, 2, 3};

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

void RotateArray(int a[], int n, int d)
{
    int temp[n];

    for (int i = 0; i < d; i++)
    {
        temp[i] = a[i];
    }

    for (int i = 0; i < n - d; i++)
    {
        a[i] = a[i + d];
    }

    for (int i = n - d, j = 0; i < n; i++)
    {
        a[i] = temp[j++];
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(int);

    int d;
    cin >> d;
    RotateArray(a, n, d);
    display(a, n);
    return 0;
}