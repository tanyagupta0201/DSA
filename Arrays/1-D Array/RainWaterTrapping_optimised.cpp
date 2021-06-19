// Two Pointer Approach (Optimised Solution)
// Google Interview Question

#include <bits/stdc++.h>
using namespace std;

int a[1000000];

int max_water_optimised(int a[], int n)
{
    int water = 0;    // To store the final answer
    int leftMax = 0;  // To store the max current height of left side
    int rightMax = 0; // To store the max current height of right side
    int l = 0;        // Counter to traverse from left side
    int r = n - 1;    // Counter to traverse from right side

    while (l <= r)
    {
        if (a[l] < a[r])
        {
            if (a[l] > leftMax)
            {
                leftMax = a[l]; // Updating leftMax
            }
            else
            {
                water += leftMax - a[l]; // Calculating the answer
            }
            l++;
        }
        else
        {
            if (a[r] > rightMax)
            {
                rightMax = a[r]; // Updating RightMax
            }
            else
            {
                water += rightMax - a[r]; // Calculating the answer
            }
            r--;
        }
    }
    return water;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << max_water_optimised(a, n) << endl;
    return 0;
}