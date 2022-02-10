// Problem Link: https://practice.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1/#

#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[], long long int n, long long int k);

// Driver program to test above functions
int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K)
{
    int i = 0, j = 0;

    list<long long int> l;     // to store negative elements
    vector<long long int> res; // to store final result

    while (j < N)
    {
        if (A[j] < 0)
        {
            l.push_back(A[j]);
        }

        if (j - i + 1 == K)
        {
            // If there are no negative elements
            if (l.empty())
            {
                res.push_back(0);
            }
            else
            {
                // if there are negative elements present in the list
                res.push_back(l.front());

                // for sliding to the next window, we need to pop out the first negative element from the list
                // if the first element of the current sliding window is not negative, then don't pop anything from the list
                if (A[i] == l.front())
                {
                    l.pop_front();
                }
            }
            i++;
        }

        j++;
    }
    return res;
}