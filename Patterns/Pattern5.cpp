/*   
Print the following pattern for N = 5

                    1
                    11
                    202
                    3003
                    40004
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    cout << 1 << endl;
    int row = 2;
    while (row <= n)
    {
        int col = 1;
        cout << row - 1;

        // Printing zeros
        while (col <= row - 2)
        {
            cout << 0;
            col++;
        }

        cout << row - 1;
        // New Line
        cout << endl;
        row++;
    }
    return 0;
}