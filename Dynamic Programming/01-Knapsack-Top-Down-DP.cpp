// 01-Knapsack code using Top Down Approach

#include <bits/stdc++.h>
using namespace std;

int knapsack(int weight[], int price[], int n, int w)
{
    // DP Matrix
    int t[n + 1][w + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < w + 1; j++)
        {
            // Base Case
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }

            // If the current weight is less than the weight of the knapsack
            else if (weight[i - 1] <= j)
            {
                // Including the current weight
                int include = price[i - 1] + t[i - 1][j - weight[i - 1]];

                // Excluding the current weight
                int exclude = t[i - 1][j];

                // Taking the max of include and exclude for max profit
                t[i][j] = max(include, exclude);
            }

            // If the current weight is more than the weight of the knapsack
            else if (weight[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][w];
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

    cout << "Maximum Profit: " << knapsack(weight, price, n, capacity) << endl;

    return 0;
}