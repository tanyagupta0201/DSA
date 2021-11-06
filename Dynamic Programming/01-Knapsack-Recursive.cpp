// 0-1 Knapsack Recursive Approach

#include <bits/stdc++.h>
using namespace std;

int knapsack(int weight[], int price[], int n, int capacity)
{
    // Base Case
    if (n == 0 || capacity == 0)
    {
        return 0;
    }

    // Recursive Case
    int ans = 0, include = 0, exclude = 0;

    // Item will be included
    if (weight[n - 1] <= capacity)
    {
        // Including the current item
        include = price[n - 1] + knapsack(weight, price, n - 1, capacity - weight[n - 1]);

        // Excluding the current item
        exclude = knapsack(weight, price, n - 1, capacity);

        // Taking the max of include and exclude for max profit
        ans = max(include, exclude);
    }
    else
    {
        // Item will be excluded
        exclude = knapsack(weight, price, n - 1, capacity);
        ans = exclude;
    }

    return ans;
}

int main()
{
    // Input the capacity of the knapsack
    int capacity;
    cin >> capacity;

    // Input the size of weight and price array
    int n;
    cin >> n;

    int weight[n], price[n];

    // Input the weight of each item
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
    }

    // Input the price of each item
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
    }

    cout << "Maximum Profit: " << knapsack(weight, price, n, capacity);
    return 0;
}
