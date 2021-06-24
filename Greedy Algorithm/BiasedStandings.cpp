#include <bits/stdc++.h>
using namespace std;

int abs(int i, int j)
{
    if ((i - j) > 0)
    {
        return (i - j);
    }
    return (j - i);
}

int main()
{
    int t, a[100000] = {0};
    cin >> t;

    while (t--)
    {
        memset(a, 0, sizeof a);
        int n, rank;
        string name;
        cin >> n;

        // Count Sort Approach
        for (int i = 0; i < n; i++)
        {
            cin >> name >> rank;
            a[rank]++;
        }

        // Greedy Approach - assign the team nearest available rank
        int actual_rank = 1;
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            while (a[i])
            {
                sum += abs(actual_rank, i);
                a[i]--; // Removing rank after assigning
                actual_rank++;
            }
        }
        cout << sum << endl;
    }

    return 0;
}