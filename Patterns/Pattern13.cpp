/*
Print the following pattern for N = 5, each number seperated by a space.

        1 2 3 4 5       
        1 2 3 4 *       
        1 2 3 * * *     
        1 2 * * * * *   
        1 * * * * * * * 

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    // First Line
    for (int i = 1; i <= n; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    // Rest n - 1 lines which have stars
    int j = 1;
    for (int row = n - 1; row >= 1; row--)
    {
        // Increasing Values
        for (int i = 1; i <= row; i++)
        {
            cout << i << " ";
        }

        // Stars (in Odd Number)
        for (int i = 1; i <= j; i++)
        {
            cout << "*"
                 << " ";
        }
        j += 2;
        cout << endl;
    }
    return 0;
}