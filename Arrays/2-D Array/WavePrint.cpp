#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, a[20][20];
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    cout << "Enter the array elements: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "The inputted array is: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "After Wave Print: ";
    for (int j = 0; j < n; j++)
    {
        if (j % 2 == 0)
        {
            for (int i = 0; i < m; i++)
            {
                cout << a[i][j] << " ";
            }
        }
        else
        {
            for (int i = m - 1; i >= 0; i--)
            {
                cout << a[i][j] << " ";
            }
        }
    }
    return 0;
}