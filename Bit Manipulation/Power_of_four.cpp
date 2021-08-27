/*

    1. 4 is also power of 2 so number of set bits should be 1 only.
    2. The position the set bit will always be at odd position. 
    3. If the position of the set bit is odd then it is a power of 4 else it is not.

*/

#include <bits/stdc++.h>
using namespace std;

bool PowerOfFour(int n)
{
    if (n < 0)
        return false;

    int pos = 0;

    if (__builtin_popcount(n) == 1)
    {
        while (n > 0)
        {
            n = n >> 1;
            pos++;
        }

        // Checking if the position of the set bit is odd
        if (pos & 1)
            return true;
    }

    return false;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;

    if (PowerOfFour(n))
    {
        cout << "Power of Four " << endl;
    }
    else
    {
        cout << "Not a power of Four " << endl;
    }

    return 0;
}