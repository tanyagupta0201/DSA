#include <bits/stdc++.h>
using namespace std;

// x < middle "<" -> 1
// x >= middle "<" -> 2
int query(int mid)
{
    cout << mid << endl;
    string res;
    cin >> res;
    if (res == "<")
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int l = 1, r = 1e6, ans = 0;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (query(mid) == 1)
        {
            r = mid - 1;
        }
        else
        {
            ans = mid;
            l = mid + 1;
        }
    }
    cout << "! " << ans;
    return 0;
}