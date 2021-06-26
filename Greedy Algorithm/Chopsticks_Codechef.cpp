#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int n, d, i, count = 0;
    cin >> n >> d;
    long long int a[n];

    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sort the chopsticks according to their length
    sort(a, a + n);

    for (i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] <= d)
        {
            count++;
            i++; // we need to go to i + 2 positions
        }
    }
    cout << count << endl;

    return 0;
}