// Print the boundary elements of the matrix

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of matrix: ";
    cin >> n;
    int a[100][100];

    cout << "Enter the elements of matrix: ";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "The matrix is :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    cout << "The boundary elements of the matrix: " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0 || j == n - 1 || i == n - 1)
            {
                cout << a[i][j] << " ";
            }
            else
            {
                cout << " "
                     << " ";
            }
        }
        cout << endl;
    }
    return 0;
}