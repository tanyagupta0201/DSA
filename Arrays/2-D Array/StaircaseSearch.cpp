// Given a matrix which has sorted rows and columns. We need to search an element by using Staircase Search method.
// Complexity: O(1)

#include <bits/stdc++.h>
using namespace std;

void StairCase_Search(int a[][20], int n, int ele)
{
    int row = 0, col = n - 1;
    while (row < n && col >= 0)
    {
        int currNumber = a[row][col];
        if (currNumber == ele)
        {
            cout << "Element found at row: " << row << " and column: " << col << endl;
            return;
        }
        else if (currNumber < ele)
        {
            row++;
        }
        else
        {
            col--;
        }
    }
    cout << "Element not found !!" << endl;
}

int main()
{
    int val = 1, n, a[20][20], ele;

    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the element to be searched: ";
    cin >> ele;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = val;
            val++;
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    StairCase_Search(a, n, ele);
    return 0;
}