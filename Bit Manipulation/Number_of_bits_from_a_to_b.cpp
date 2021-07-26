// Find the number of bits that will change from a to b

#include <bits/stdc++.h>
using namespace std;

int Number_of_bits(int a, int b)
{
    int n = a ^ b; // XOR is used as it will generate one where two bits will be different

    int count = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        count++;
    }
    return count;
}

int main()
{
    int a = 22, b = 27;
    cout << Number_of_bits(a, b) << endl;
    return 0;
}