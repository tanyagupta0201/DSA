// Based on Inclusion Exclusion Principle
// Find out number of numbers between 1 and n which are divisible by any of the numbers less than 20

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int t;
    cin >> t;

    ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};

    while (t--)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        ll subsets = (1 << 8) - 1; // where 8 is the size of the array primes and -1 is done as we are not including null set (2 ^ N - 1)

        for (int i = 1; i <= subsets; i++)
        {
            ll denominator = 1ll;
            ll setBits = __builtin_popcount(i); // Builtin function to find number of set bits

            for (ll j = 0; j <= 7; j++) // As each number has 8 bits
            {
                if (i & (1 << j))
                {
                    denominator = denominator * primes[j];
                }
            }

            if (setBits & 1)
            {
                ans += n / denominator;
            }
            else
            {
                ans -= n / denominator;
            }
        }
        cout << ans << endl;
    }
    return 0;
}