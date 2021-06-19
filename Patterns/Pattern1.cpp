/*   
Print the following pattern for N = 5

                    1
                   232
                  34543 
                 4567654 
                567898765
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;

    // Rows
    for (int i = 1; i <= n; i++)
    {
        // Spaces
        for (int spaces = 1; spaces <= n - i; spaces++)
        {
            cout << " "
                 << "\t";
        }

        // Increasing Values
        int val = i;
        for (int j = 1; j <= i; j++)
        {
            cout << val << "\t";
            val++;
        }

        // Decreasing Numbers
        val = val - 2;
        for (int j = 1; j <= i - 1; j++)
        {
            cout << val << "\t";
            val--;
        }
        // Print a New line
        cout << endl;
    }
    return 0;
}