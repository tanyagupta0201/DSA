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
        include = price[n - 1] + knapsack(weight, price, n - 1, capacity - weight[n - 1]);
    }
    else
    {
        // Item will be excluded
        exclude = knapsack(weight, price, n - 1, capacity);
    }

    // We need to calculate maximum profit
    ans = max(include, exclude);

    return ans;
}

int main()
{
    int capacity = 7;
    int weight[] = {1, 2, 3, 5};
    int price[] = {40, 20, 30, 100};

    int n = sizeof(weight) / sizeof(int);

    cout << "Maximum Profit: " << knapsack(weight, price, n, capacity);
    return 0;
}