/*
Print the following pattern for N = 5
            
                *****    
                 *   *   
                  *   *  
                   *   * 
                    *****
                    
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    for (int row = 1; row <= n; row++)
    {
        // Spaces
        for (int i = 1; i < row; i++)
        {
            cout << " ";
        }

        if (row == 1 or row == n)
        {
            // For first and last line
            for (int i = 1; i <= n; i++)
            {
                cout << "*";
            }
        }
        else
        {
            // For other lines
            cout << "*";
            for (int i = 1; i <= n - 2; i++)
            {
                cout << " ";
            }
            cout << "*";
        }

        // Next Line
        cout << endl;
    }

    return 0;
}