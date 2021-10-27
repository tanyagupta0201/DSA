#include <bits/stdc++.h>
using namespace std;

// Function to print the array
void printArr(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}

// Function to find the maximum element from the array
int getMax(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

// Function to perform counting sort
void countSort(int a[], int n)
{
    int output[n + 1];
    int max = getMax(a, n);
    int count[max + 1]; //create count array with size [max+1]

    // Initialize count array with all zeros
    for (int i = 0; i <= max; ++i)
    {
        count[i] = 0;
    }

    // Store the count of each element
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
    }

    // Find cumulative frequency
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i - 1];
    }

    // This loop will find the index of each element of the original array in count array, and place the elements in output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--; // decrease count for same numbers
    }

    // Store the sorted elements into main array
    for (int i = 0; i < n; i++)
    {
        a[i] = output[i];
    }
}

int main()
{
    int a[100], n;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Array before sorting: " << endl;
    printArr(a, n);

    countSort(a, n);

    cout << "\nArray after sorting: " << endl;
    printArr(a, n);

    return 0;
}