#include <bits/stdc++.h>
using namespace std;

void StockSpan(int prices[], int n, int span[])
{
    stack<int> s; // Indices of the days
    s.push(0);
    span[0] = 1;

    // Loop for rest of the days
    for (int i = 1; i < n; i++)
    {
        int CurrPrice = prices[i];

        // Topmost element that is higher than current prices
        while (!s.empty() and prices[s.top()] <= CurrPrice)
        {
            s.pop();
        }

        if (!s.empty()) // As s.top() does not work on empty stack
        {
            int prev_highest = s.top();
            span[i] = i - prev_highest;
        }
        else
        {
            span[i] = i + 1;
        }
        s.push(i);
    }
}

int main()
{
    int prices[] = {100, 80, 60, 70, 60, 75, 85};
    int n = sizeof(prices) / sizeof(int);
    int span[100000] = {0};

    StockSpan(prices, n, span);
    for (int i = 0; i < n; i++)
    {
        cout << span[i] << " ";
    }
    return 0;
}