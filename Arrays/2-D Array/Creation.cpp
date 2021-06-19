#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, a[20][20];
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;

    int val = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = val;
            cout << a[i][j] << " ";
            val++;
        }
        cout << endl;
    }
    return 0;
}