// Given a number N, find the number of set bits in binary representation of it.
// N = 13, Binary = 1101, Output = 3

#include <bits/stdc++.h>
using namespace std;

// First Method
int CountBits(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += (n & 1);
        n = n >> 1;
    }
    return ans;
}

// Second Method
int CountBitsFast(int n)
{
    int ans = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        ans++;
    }
    return ans;
}

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << CountBits(n) << endl;
    cout << CountBitsFast(n) << endl;
    cout << __builtin_popcount(n) << endl; // Inbuilt function to count number of set bits

    return 0;
}