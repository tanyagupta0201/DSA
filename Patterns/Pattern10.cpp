/*   
SWASTIKA PATTERN
Print the following pattern for N = 7

                    *  ****
                    *  *
                    *  *
                    *******
                       *  *
                       *  *
                    ****  *
                
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    // First Component
    // Star
    cout << "*";

    // Spaces
    for (int i = 1; i <= (n - 3) / 2; i++)
    {
        cout << " ";
    }

    // Stars
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        cout << "*";
    }
    cout << endl;

    // Second Component
    for (int rows = 1; rows <= (n - 3) / 2; rows++)
    {
        // Star
        cout << "*";

        // Spaces
        for (int i = 1; i <= (n - 3) / 2; i++)
        {
            cout << " ";
        }

        // Star
        cout << "*" << endl;
    }

    // Third Component
    // Printing n stars
    for (int i = 1; i <= n; i++)
    {
        cout << "*";
    }
    cout << endl;

    // Fourth Component
    for (int rows = 1; rows <= (n - 3) / 2; rows++)
    {
        // Spaces
        for (int i = 0; i < (n - 3) / 2 + 1; i++)
        {
            cout << " ";
        }

        // Star
        cout << "*";

        // Spaces
        for (int i = 1; i <= (n - 3) / 2; i++)
        {
            cout << " ";
        }

        // Star
        cout << "*" << endl;
    }

    // Fifth Component
    // Star
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        cout << "*";
    }

    // Spaces
    for (int i = 1; i <= (n - 3) / 2; i++)
    {
        cout << " ";
    }

    // Star
    cout << "*" << endl;

    return 0;
}
