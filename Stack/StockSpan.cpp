// TC = O(N), SC = O(N)

class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       stack<pair<int, int>> st; // {Next greatest element. index}
       
       vector<int> v(n);
    

       for (int i = 0; i < n; i++)
       {
           if (st.size() > 0)
           {
               while (st.size() > 0 && st.top().first <= price[i])
               {
                  st.pop();
               }
           }

           if (!st.empty())
               v[i] = st.top().second;
           else
               v[i] = -1;

           st.push({price[i], i});
        }

        for(int i = 0; i < v.size(); i++)
        {
            v[i] = i - v[i]; // curr index - next greatest element index
        }
       
       return v;
    }
};


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
