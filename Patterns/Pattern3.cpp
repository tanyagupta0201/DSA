/*   
Print the following pattern for N = 5

                    ABCDE
                    ABCD
                    ABC
                    AB
                    A

*/

#include <bits/stdc++.h>
using namespace std;

void ABCD_Pattern(int n)
{
    // Rows
    for (int i = 1; i <= n; i++)
    {
        int cnt_alphabets = n - i + 1;
        char alphabet = 'A';

        for (int j = 1; j <= cnt_alphabets; j++)
        {
            cout << alphabet;
            alphabet++;
        }
        // New Line
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter N: ";
    cin >> n;
    ABCD_Pattern(n);
    return 0;
}