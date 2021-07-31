// Power of a number (base ^ exp) using bit manipulation

#include <bits/stdc++.h>
using namespace std;

int Power_Optimised(int base, int exp)
{
    int ans = 1;

    while (exp > 0)
    {
        int lastBit = (exp & 1);

        if (lastBit)
        {
            ans = ans * base;
        }

        base = base * base;
        exp = exp >> 1;
    }

    return ans;
}

int main()
{
    int base, exp;

    cout << "Enter base number: ";
    cin >> base;

    cout << "Enter exponent: ";
    cin >> exp;

    cout << Power_Optimised(base, exp);

    return 0;
}