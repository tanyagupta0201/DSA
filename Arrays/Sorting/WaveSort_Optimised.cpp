// Time Complexity: O(n)

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

    // Traverse all even elements
    for (int i = 0; i < n; i += 2)
    {
        // If the current even element is smaller than previous element
        if (a[i] < a[i - 1] and i != 0)
        {
            swap(a[i], a[i - 1]);
        }
        // If the current even element is smaller than next element
        if (a[i] < a[i + 1] and i != (n - 1))
        {
            swap(a[i], a[i + 1]);
        }
    }

    cout << "Array after Wave Sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}