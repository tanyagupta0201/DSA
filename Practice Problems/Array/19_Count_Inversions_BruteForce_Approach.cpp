// Inversion Count
// Brute Force Approach

#include <bits/stdc++.h>
using namespace std;

int CountInversionArray(int a[], int n)
{
    int i, j, c = 0;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                c++;
        }
    }
    return c;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int a[n];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Number of inversions are " << CountInversionArray(a, n) << endl;

    return 0;
}