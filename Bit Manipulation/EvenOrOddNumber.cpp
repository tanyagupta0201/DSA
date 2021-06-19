#include <bits/stdc++.h>
using namespace std;

bool isevenorodd(int n)
{
    return (n & 1); //It checks for odd number
}
int main()
{
    int n;
    cin >> n;
    bool result = isevenorodd(n);
    if (result)
    {
        cout << "Odd Number";
    }
    else
    {
        cout << "Even Number";
    }

    return 0;
}