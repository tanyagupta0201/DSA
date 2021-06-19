/*  Print the pattern for N = 5

    *        *
    **      **
    ***    ***
    ****  ****
    **********
    ****  ****
    ***    ***
    **      **
    *        *

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, spaces;
    cout << "Enter n: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        // for *
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // Spaces
        spaces = 2 * (n - i) - 1;
        for (int j = spaces; j >= 0; j--)
        {
            cout << " ";
        }

        // For *
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // Lower Part
    for (int i = n - 1; i >= 0; i--)
    {
        // for *
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }

        // Spaces
        spaces = 2 * (n - i) - 1;
        for (int j = spaces; j >= 0; j--)
        {
            cout << " ";
        }

        // For *
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}