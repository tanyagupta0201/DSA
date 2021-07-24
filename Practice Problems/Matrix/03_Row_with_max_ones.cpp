/*  
      Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s. 

      Example:  

      Input matrix
      0 1 1 1
      0 0 1 1
      1 1 1 1  // this row has maximum 1s
      0 0 0 0

      Output: 2
  
*/

#include <bits/stdc++.h>
using namespace std;

int max_ones(int a[][20], int m, int n)
{
    int j = n - 1;
    int row = 0;

    for (int i = 0; i < m; i++)
    {
        while (j >= 0 and a[i][j] == 1)
        {
            j--;
            row = i;
        }
    }
    return row;
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

    cout << max_ones(a, m, n);

    return 0;
}
