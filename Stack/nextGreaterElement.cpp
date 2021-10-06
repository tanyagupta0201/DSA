// GFG problem link : https://practice.geeksforgeeks.org/problems/next-larger-element-1587115620/1#
// This is the optimized approach in O(n) time complexity


#include<bits/stdc++.h>
using namespace std;

vector<long long> nextLargerElement(vector<long long> arr, int n) {
    vector<long long> ans(n);
    stack<long long > s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && arr[i] >= s.top())
            s.pop();
        if (!s.empty())
            ans[i] = s.top();
        else
            ans[i] = -1;
        s.push(arr[i]);
    }
    return ans;
}