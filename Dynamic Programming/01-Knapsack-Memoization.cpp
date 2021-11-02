#include <bits/stdc++.h>
using namespace std;

int knapsack(int weight[], int price[], int n, int capacity)
{
    int t[10][10];

    // Intializing the matrix with -1
    memset(t, -1, sizeof(t));

    // Base Case
    if (n == 0 || capacity == 0)
    {
        return 0;
    }

    // If there exists a value which is not -1, then return it
    if (t[n][capacity] != -1)
    {
        return t[n][capacity];
    }

    // Recursive Case
    int include = 0, exclude = 0;

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
    return t[n][capacity] = max(include, exclude);
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