/* Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item or don’t pick it (0-1 property). */

#include <bits/stdc++.h>
using namespace std;

int profit(int n, int c, int *weight, int *price)
{
    // Base Case
    if (n == 0 || c == 0)
    {
        return 0;
    }

    // Recursive Case
    int ans = 0, include = 0, exclude = 0;

    // Including the item
    if (weight[n - 1] <= c)
    {
        include = price[n - 1] + profit(n - 1, c - weight[n - 1], weight, price);
    }

    // Excluding the item
    exclude = profit(n - 1, c, weight, price);

    ans = max(include, exclude);
    return ans;
}

int main()
{
    int num_of_items = 4, capacity = 7;
    int weight[] = {1, 2, 3, 5};
    int price[] = {40, 20, 30, 100};

    cout << "The maximum profit is rupees " << profit(num_of_items, capacity, weight, price) << endl;

    return 0;
}