#include <bits/stdc++.h>
using namespace std;

int main()
{
    int diff, n, a[9000];

    while (1)
    {
        // Take input current test case
        int load = 0, max_load = 0;
        cin >> n;

        // Stop taking input if n = -1
        if (n == -1)
        {
            break;
        }

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            load += a[i];
        }

        if (load % n != 0)
        {
            cout << -1 << endl;
            continue;
        }

        // Find the load that is to be divided equally
        load = load / n;

        diff = 0;
        // Greedy step
        for (int i = 0; i < n; i++)
        {
            // Find the difference between final load to be assigned and current load
            diff += (a[i] - load);
            int ans = abs(diff);
            max_load = max(ans, max_load);
        }
        cout << max_load << endl;
    }
    return 0;
}