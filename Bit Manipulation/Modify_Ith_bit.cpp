/*   
    Modify a bit at a given position
    Given a number n, a position p and a binary value b, we need to change the bit at position p in n to value b.

*/

#include <bits/stdc++.h>
using namespace std;

int Modify_Bit(int n, int pos, int b)
{
    int mask = ~(1 << pos);
    int cleared_bit = n & mask;
    int ans = cleared_bit | (b << pos);
    return ans;
}

int main()
{
    int n, pos, b;
    cin >> n >> pos >> b;

    cout << Modify_Bit(n, pos, b);

    return 0;
}