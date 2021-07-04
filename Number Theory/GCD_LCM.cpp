#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return (a == 0) ? b : gcd(b % a, a);
}

int main()
{
    int a = 15, b = 10;

    cout << "GCD: " << gcd(a, b) << endl;
    cout << "LCM: " << (a * b) / gcd(a, b) << endl;
    return 0;
}