/*
Print the following pattern for N = 7

        1******
        12*****
        123****
        1234***
        12345**
        123456*
        1234567

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter N:";
    cin >> n;

    for (int Row = 1; Row <= n; Row++)
    {
        // Values in increasing order
        for (int i = 1; i <= Row; i++)
        {
            cout << i;
        }

        // Stars
        for (int i = 1; i <= n - Row; i++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}