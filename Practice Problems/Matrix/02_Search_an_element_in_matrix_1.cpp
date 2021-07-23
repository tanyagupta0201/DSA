#include <bits/stdc++.h>
using namespace std;

void Search(int a[][20], int m, int n, int x)
{
    int i = 0, j = m - 1;
    while (i < n and j >= 0)
    {
        if (a[i][j] == x)
        {
            cout << x << " found at " << i << ", " << j;
            return;
        }
        if (a[i][j] > x)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int a[20][20];
    int m, n, x;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "Enter the element to be searched: ";
    cin >> x;

    Search(a, m, n, x);
    return 0;
}