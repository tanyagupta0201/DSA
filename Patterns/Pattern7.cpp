/*   
Print the following pattern for N = 4, each number should be seperated by a tab.

                    1     1
                    12   21
                    123 321
                    1234321

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        // Increasing Numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j << "\t";
        }

        // Spaces
        int spaces = 2 * (n - i) - 1;
        for (int j = spaces; j > 0; j--)
        {
            cout << " "
                 << "\t";
        }

        // Decreasing Numbers
        for (int j = i; j > 0; j--)
        {
            // j == n ? cout << " " : cout << j; (This is the alternative line)
            if (j != n)
            {
                cout << j << "\t";
            }
        }

        // New Line
        cout << endl;
    }

    return 0;
}