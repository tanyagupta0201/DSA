/* 
Print the following pattern for N = 5, each number seperated by a space.

    
        1     
        11    
        111   
        1001  
        11111 
        100001
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    int row = 1;
    while (row <= n)
    {
        int col = 1;
        // Odd Row
        if (row % 2 != 0)
        {
            while (col <= row)
            {
                cout << 1;
                col++;
            }
        }
        else
        {
            // Even Row
            cout << 1;
            while (col <= row - 2)
            {
                cout << 0;
                col++;
            }
            cout << 1;
        }
        cout << endl;
        row++;
    }
    return 0;
}