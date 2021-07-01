/*
    Replace each element of the array with it's corresponding rank

    Example:  arr[] = {100, 5, 70, 3}
              Output = [1, 3, 2, 4]

              arr[] = {1, 2, 2, 6}
              Output = [4, 2, 2, 1]

*/

#include <bits/stdc++.h>
using namespace std;

int compare(int n1, int n2)
{
    return n1 > n2;
}

void ranks(int a[], int n)
{
    map<int, int> m;

    int b[n];
    // Copy the elements of array a into array b
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i];
    }

    // Sort in descending order
    sort(b, b + n, compare);

    for (int index = 0; index < n; index++)
    {
        m.insert(make_pair(b[index], index + 1));
    }

    // Assigning rank to the elements
    for (int index = 0; index < n; index++)
    {
        a[index] = m[a[index]];
    }
}

int main()
{
    int a[] = {200, 50, 250, 100};
    int n = sizeof(a) / sizeof(int);

    ranks(a, n);

    cout << "[";
    for (int i = 0; i < n - 1; i++)
    {
        cout << a[i] << ", ";
    }
    cout << a[n - 1] << "]";

    return 0;
}
