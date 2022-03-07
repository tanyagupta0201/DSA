// Count all subsequences whose sum is equal to K

#include <bits/stdc++.h>
using namespace std;

int AllSubseqences(int idx, vector<int> arr, int n, vector<int> ans, int K, int sum)
{
    // Base Case
    if (idx >= n)
    {
        if (sum == K)
            return 1;
        else
            return 0;
    }

    // Pick a number
    ans.push_back(arr[idx]);
    sum += arr[idx];

    int left = AllSubseqences(idx + 1, arr, n, ans, K, sum);

    ans.pop_back();
    sum -= arr[idx];

    // Do not pick a number
    int right = AllSubseqences(idx + 1, arr, n, ans, K, sum);

    return left + right;
}

int main()
{
    vector<int> arr{1, 2, 1};
    int n = arr.size();

    vector<int> ans;

    int K = 2;

    cout << "Number of subsequences whose sum is equal to K = " << AllSubseqences(0, arr, n, ans, K, 0) << endl;

    return 0;
}