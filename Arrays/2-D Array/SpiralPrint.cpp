/*
    
       Input:  1   2   3   4  5   6
               7   8   9  10  11  12
               13  14  15 16  17  18
               
       Output: 1 2 3 4 5 6 12 18 17 16 15 14 13 7 8 9 10 11
       
       Explanation :The output is matrix in spiral format.

*/

#include <bits/stdc++.h>
using namespace std;

void Spiral(int a[][20], int m, int n)
{
    int direction = 0;
    int top = 0, bottom = m - 1, left = 0, right = n - 1;

    while (top <= bottom and left <= right)
    {
        if (direction == 0)
        {
            for (int i = left; i <= right; i++)
            {
                cout << a[top][i] << " ";
            }
            top++;
        }
        else if (direction == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                cout << a[i][right] << " ";
            }
            right--;
        }
        else if (direction == 2)
        {
            for (int i = right; i >= left; i--)
            {
                cout << a[bottom][i] << " ";
            }
            bottom--;
        }
        else if (direction == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                cout << a[i][left] << " ";
            }
            left++;
        }
        direction = (direction + 1) % 4;
    }
}

int main()
{
    int a[20][20];
    int m, n;
    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << endl;
    cout << "The Spiral Print of matrix: ";
    Spiral(a, m, n);
    return 0;
}
