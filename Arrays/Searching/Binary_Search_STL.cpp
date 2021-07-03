// Binary Search STL

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 2, 4, 8, 9, 11, 13, 16, 21, 34, 56, 57, 89, 123, 165};
    int n = sizeof(arr) / sizeof(int);

    int key;
    cin >> key;

    bool present = binary_search(arr, arr + n, key);

    if (present)
    {
        cout << key << " is present !!" << endl;
    }
    else
    {
        cout << key << " is not present !!" << endl;
    }

    return 0;
}