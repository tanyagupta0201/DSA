// Find the minimum number of coins to change the money

#include <bits/stdc++.h>
using namespace std;

int make_change(int *coins, int n, int money)
{
    int ans = 0;
    while (money > 0)
    {
        int idx = upper_bound(coins, coins + n, money) - 1 - coins;
        cout << coins[idx] << " + ";
        money = money - coins[idx];
        ans++;
    }
    cout << endl;
    return ans;
}

int main()
{
    int money;
    cin >> money;

    int coins[] = {1, 2, 5, 10, 50, 100, 200, 500, 2000};
    int t;
    t = sizeof(coins) / sizeof(int);
    cout << "Minimum number of coins needed: " << make_change(coins, t, money) << endl;

    return 0;
}