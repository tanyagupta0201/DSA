/*

Print the following pattern for N = 5

        5                   5 
        5 4               4 5 
        5 4 3           3 4 5 
        5 4 3 2       2 3 4 5 
        5 4 3 2 1   1 2 3 4 5 
        5 4 3 2 1 0 1 2 3 4 5 
        5 4 3 2 1   1 2 3 4 5 
        5 4 3 2       2 3 4 5 
        5 4 3           3 4 5 
        5 4               4 5 
        5                   5 

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    for (int row = 1; row <= n + 1; row++)
    {
        int val = n;
        // Number
        for (int j = 1; j <= row; j++)
        {
            cout << val << " ";
            val--;
        }

        // Spaces
        int space = 2 * (n - row) + 1; //
        for (int j = space; j > 0; j--)
        {
            cout << "  ";
        }

        // Number
        val++;
        for (int j = 1; j <= row; j++)
        {
            val == 0 ? cout << "" : cout << val << " ";
            val++;
        }
        cout << endl;
    }

    // Lower Half
    for (int row = n; row > 0; row--)
    {
        int val = n;
        // Number
        for (int j = 1; j <= row; j++)
        {
            cout << val << " ";
            val--;
        }

        // Spaces
        int space = 2 * (n - row) + 1;
        for (int j = space; j > 0; j--)
        {
            cout << "  ";
        }

        // Number
        val++;
        for (int j = 1; j <= row; j++)
        {
            cout << val << " ";
            val++;
        }
        cout << endl;
    }

    return 0;
}