//Given n number of steps and k number of jumps. Find the total number of ways to reach the final step.

#include <bits/stdc++.h>
using namespace std;

int ladders(int n, int k)
{
    //Base Case
    if (n == 0)
    {
        return 1;
    }

    if (n < 0)
    {
        return 0;
    }

    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += ladders(n - i, k);
    }
    return ans;
}

int main()
{
    int n, k;
    cout << "Enter the number of steps: ";
    cin >> n;
    cout << "Enter the number of jumps: ";
    cin >> k;
    cout << "The total number of ways: " << ladders(n, k) << endl;
    return 0;
}