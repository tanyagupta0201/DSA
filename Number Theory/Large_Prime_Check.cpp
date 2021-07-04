// Space Optimised Sieve using Bitset
// Check if a Large number is a prime number or not ~ 10 ^ 12
// Sieve Limitation upto - 10 ^ 7

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

const int n = 10000000;
bitset<10000005> b;
vector<int> primes;

void Sieve()
{
    // Set all bits
    b.set(); // 1, 1, 1, 1, .....

    b[0] = b[1] = 0;

    for (long long int i = 2; i <= n; i++)
    {
        if (b[i])
        {
            primes.push_back(i);
            for (long long int j = i * i; j <= n; j = j + i)
            {
                b[j] = 0;
            }
        }
    }
}

bool isPrime(long long int num)
{
    if (num <= n)
    {
        return b[num] == 1 ? true : false;
    }

    for (long long int i = 0; primes[i] * (long long)primes[i] <= num; i++)
    {
        if (num % primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    Sieve();

    if (isPrime(2147483647)) // 10 Digit Number
    {
        cout << "Prime Number !!" << endl;
    }
    else
    {
        cout << "Not a Prime Number !!" << endl;
    }

    return 0;
}