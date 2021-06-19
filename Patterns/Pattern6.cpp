/*   
Print the following pattern for N = 5, each number seperated by a tab.

                    1
                    2   2
                    3   0   3
                    4   0   0   4
                    5   0   0   0   5
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    cout << 1 << endl;
    cout << 2 << "\t" << 2 << endl;

    int row = 3;
    while (row <= n)
    {
        int col = 1;
        cout << row << "\t";

        while (col <= row - 2)
        {
            cout << 0 << "\t";
            col++;
        }

        cout << row << "\t";
        cout << endl;
        row++;
    }
    return 0;
}