// Check whether an inputted number is a power of two or not.

#include <bits/stdc++.h>
using namespace std;

bool isPowerofTwo(long long n)
{
    if (n == 0)
    {
        return false;
    }

    while (n != 1)
    {
        if (n % 2 != 0)
        {
            return false;
        }
        else
        {
            n = n / 2;
        }
    }
    return true;
}

int main()
{
    long long n;
    cout << "Enter the number: ";
    cin >> n;

    if (isPowerofTwo(n))
    {
        cout << "YES !!" << endl;
    }
    else
    {
        cout << "NO !!" << endl;
    }

    return 0;
}