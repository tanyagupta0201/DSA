// Binary Search (Divide and Conquer)

#include <bits/stdc++.h>
using namespace std;

int BinarySearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1, 2, 4, 8, 9, 11, 13, 16, 21, 34, 56, 57, 89, 123, 165};
    int n = sizeof(arr) / sizeof(int);

    int key;
    cin >> key;

    int result = BinarySearch(arr, n, key);

    (result == -1) ? cout << "Element is not present !!" : cout << "Element is present at index " << result;
    return 0;
}
