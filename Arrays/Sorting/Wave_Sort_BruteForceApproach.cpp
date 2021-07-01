// Time Complexity: O(n log n)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[100], n;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    // Sort the array
    sort(a, a + n);
    for (int i = 0; i < n - 1; i += 2)
    {
        // Swapping the elements in pairs
        swap(a[i], a[i + 1]);
    }

    cout << "Array after Wave Sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}