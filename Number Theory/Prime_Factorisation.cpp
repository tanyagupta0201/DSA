// Calculate all the prime factors of the inputted number

#include <bits/stdc++.h>
using namespace std;

void PrimeFactors(int n)
{
    vector<pair<int, int>> factors;
    int i, count = 0;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            // Keep on dividing till it is divisible
            count = 0;
            while (n % i == 0)
            {
                count++;
                n = n / i;
            }
            factors.push_back(make_pair(i, count));
        }
    }
    if (n != 1)
    {
        // Whatever is left is prime number itself
        factors.push_back(make_pair(n, 1));
    }

    // Print the factors
    cout << "The factors are: " << endl;
    for (auto x : factors)
    {
        cout << x.first << "^" << x.second << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    PrimeFactors(n);
    return 0;
}