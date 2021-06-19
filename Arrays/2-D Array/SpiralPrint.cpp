#include <bits/stdc++.h>
using namespace std;

void Spiral(int a[][20], int m, int n)
{
    int StartRow = 0, StartCol = 0, EndRow = m - 1, EndCol = n - 1;

    while (StartRow <= EndRow && StartCol <= EndCol)
    {
        // First Row
        for (int i = StartCol; i <= EndCol; i++)
        {
            cout << a[StartRow][i] << " ";
        }
        StartRow++;

        // End Column
        for (int i = StartRow; i <= EndCol; i++)
        {
            cout << a[i][EndCol] << " ";
        }
        EndCol--;

        // Bottom Row
        if (EndRow > StartRow)
        {
            for (int i = EndCol; i >= StartCol; i--)
            {
                cout << a[EndRow][i] << " ";
            }
        }
        EndRow--;

        // Start Column
        if (EndCol > StartCol)
        {
            for (int i = EndRow; i >= StartRow; i--)
            {
                cout << a[i][StartCol] << " ";
            }
        }
        StartCol++;
    }
}

int main()
{
    int m, n, a[20][20];
    cout << "Enter number of rows and columns: ";
    cin >> m >> n;

    cout << "Enter the elements of the matrix: " << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Matrix after Spiral Print: " << endl;
    Spiral(a, m, n);
    return 0;
}