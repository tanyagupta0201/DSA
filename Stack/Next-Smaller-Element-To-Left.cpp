#include <bits/stdc++.h>
using namespace std;

vector<int> NGE_To_Left(vector<int> arr, int n)
{
    vector<int> v(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (st.size() > 0)
        {
            while (st.size() > 0 && st.top() >= arr[i])
            {
                st.pop();
            }
        }

        if (!st.empty())
            v[i] = st.top();
        else
            v[i] = -1;

        st.push(arr[i]);
    }

    return v;
}

int main()
{
    int n = 5;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = NGE_To_Left(arr, n);

    for (auto it : ans)
        cout << it << " ";

    return 0;
}