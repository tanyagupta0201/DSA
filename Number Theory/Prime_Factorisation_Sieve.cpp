#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> PrimeSieve(int *p, long long n)
{
    p[2] = 1;
    p[0] = p[1] = 0;

    for (long long i = 3; i <= n; i += 2)
    {
        p[i] = 1;
    }

    for (long long i = 3; i <= n; i += 2)
    {
        if (p[i] == 1)
        {
            for (long long j = i * i; j <= n; j += i)
            {
                p[j] = 0;
            }
        }
    }
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i <= n; i += 2)
    {
        primes.push_back(i);
    }
    return primes;
}

vector<int> factorize(int num, vector<int> &primes)
{
    vector<int> factors;
    factors.clear();
    int i = 0;
    int p = primes[i];

    while (p * p <= num)
    {
        if (num % p == 0)
        {
            factors.push_back(p);
            while (num % p == 0)
            {
                num = num / p;
            }
        }
        i++;
        p = primes[i];
    }
    if (num != 1)
    {
        factors.push_back(num);
    }
    return factors;
}

int main()
{
    int n;
    cin >> n;
    int p[n] = {0};
    vector<int> primes = PrimeSieve(p, n);

    int t;
    cout << "Enter number of test cases: ";
    cin >> t;
    while (t--)
    {
        int num;
        cout << "Enter the number: ";
        cin >> num;
        vector<int> factors = factorize(num, primes);

        cout << "The prime factors of " << num << " are: " << endl;
        for (auto f : factors)
        {
            cout << f << " " << endl;
        }
        cout << endl;
    }
    return 0;
}