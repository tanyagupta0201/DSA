// Given an array A[] of N integers and an index Key. Your task is to print the element present at index key in the array.

#include <bits/stdc++.h>
using namespace std;

int FindElement(int arr[], int n, int key)
{
    return arr[key];
}

int main()
{
    int arr[1000];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cin >> key;

    cout << FindElement(arr, n, key);

    return 0;
}