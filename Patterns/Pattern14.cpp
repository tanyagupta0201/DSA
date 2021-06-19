/*
PASCAL'S TRIANGLE
Print the following pattern for N = 4

                1  
               1 1
              1 2 1
             1 3 3 1

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    // Rows
    for (int i = 0; i < n; i++)
    {
        int num = 1;
        // Spaces
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << " ";
        }

        // Numbers
        for (int j = 0; j <= i; j++)
        {
            cout << num << " ";
            num = num * (i - j) / (j + 1);
        }

        // Next Line
        cout << endl;
    }
    return 0;
}