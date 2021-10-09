#include <bits/stdc++.h>
using namespace std;

int p[1000005];
void PrimeSieve(int *p, long long n)
{
    //First mark all odd numbers as prime numbers
    for (long long i = 3; i <= n; i += 2)
    {
        p[i] = 1;
    }
    //Sieve
    for (long long i = 3; i <= n; i = i + 2)
    {
        //if the current number is not marked then it is prime
        if (p[i] == 1)
        {
            //Mark all the multiples of i as not prime
            for (long long j = i * i; j <= n; j += i)
            {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;
}

int main()
{
    int n;
    cout << "Enter the range n: ";
    cin >> n;
    p[1000005] = {0};
    PrimeSieve(p, n);

    //Lets print prime numbers upto range n
    for (int i = 0; i <= n; i++)
    {
        if (p[i] == 1)
        {
            cout << i << " ";
        }
    }

    return 0;
}