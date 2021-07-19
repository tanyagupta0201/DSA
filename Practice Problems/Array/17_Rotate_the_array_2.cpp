#include <bits/stdc++.h>
using namespace std;

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void rotate(int a[], int d, int n)
{
    if (d == 0)
    {
        return;
    }
    d = d % n;  // When d > n 
}

void Reverse(int a[], int start, int end)
{
    int t;
    while (start < end)
    {
        t = a[start];
        a[start] = a[end];
        a[end] = t;
        start++;
        end--;
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(a) / sizeof(int);

    int d = 3;
    // cin >> d;

    rotate(a, d, n);
    Reverse(a, 0, d - 1);
    Reverse(a, d, n - 1);
    Reverse(a, 0, n - 1);
    display(a, n);

    return 0;
}
