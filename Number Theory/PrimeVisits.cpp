// We need to find out the total number of prime numbers in a given range(a, b).
// Constraints: a, b <= 1000000 and t <= 1000

#include <bits/stdc++.h>
using namespace std;

int p[1000005], csum[1000005];

void PrimeSieve(int *p, long long n)
{
    // Mark all the odd numbers as prime
    for (long long i = 3; i <= n; i += 2)
    {
        p[i] = 1;
    }

    for (long long i = 3; i <= n; i += 2)
    {
        if (p[i] == 1)
        {
            // Mark all the multiples of i as not prime
            for (long long j = i * i; j <= n; j = j + i)
            {
                p[j] = 0;
            }
        }
    }
    // Special Case
    p[0] = p[1] = 0;
    p[2] = 1;
}

int main()
{
    int n;
    cout << "Enter the range n: ";
    cin >> n;
    p[1000005] = {0};
    PrimeSieve(p, n);

    // Precompute the primes upto an index i
    for (int i = 1; i <= n; i++)
    {
        csum[i] = csum[i - 1] + p[i];
    }

    // Now enter the number of test cases
    int t;
    cout << "Enter the number of test cases: ";
    cin >> t;

    while (t--)
    {
        int a, b;
        cout << "Enter the range: ";
        cin >> a >> b;
        cout << "The number of prime numbers in the given range: " << csum[b] - csum[a - 1] << endl;
    }

    return 0;
}