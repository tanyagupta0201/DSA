// Quick Sort (Based on Divide and Conquer Technique)
// Worst Case Complexity: O(n ^2), Best Case Complexity: O(n log n)

#include <bits/stdc++.h>
using namespace std;

void Display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

// Partition Algorithm
// lb - lower bound, ub - upper bound
int Partition(int a[], int lb, int ub)
{
    int pivot = a[lb];  // Picking the first element of the array as pivot
    int start = lb, end = ub;

    while (start < end)
    {
        // Searching the element which is greater than pivot from the starting of the array
        while (a[start] <= pivot)
        {
            start++;
        }

        // Searching the element which is smaller or equal than pivot from the ending of the array
        while (a[end] > pivot)
        {
            end--;
        }

        if (start < end)
        {
            swap(a[start], a[end]);
        }
    }
    swap(a[lb], a[end]);
    return end;
}

void Quick_Sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int location = Partition(a, lb, ub);
        Quick_Sort(a, lb, location - 1);
        Quick_Sort(a, location + 1, ub);
    }
}

int main()
{
    int a[] = {3, 9, 1, 13, 15, 9, 2, 9, 17, 21, 12, 30, 5};
    int n = sizeof(a) / sizeof(int);

    Quick_Sort(a, 0, n - 1);
    Display(a, n);
    return 0;
}
