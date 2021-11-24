// Radix Sort in C++ Programming
#include <bits/stdc++.h>
using namespace std;

void countingSort(int array[], int n, int place)
{
    int output[n];
    int count[10];

    for (int i = 0; i < 10; ++i)
        count[i] = 0;

    // Calculate count of elements
    for (int i = 0; i < n; i++)
        count[(array[i] / place) % 10]++;

    // Calculate cumulative count
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Place the elements in sorted order
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
        array[i] = output[i];
}

// Main function to implement radix sort
void radixsort(int array[], int n)
{
    // Get maximum element
    int maxi = *max_element(array, array + n);

    // Apply counting sort to sort elements based on place value.
    for (int place = 1; maxi / place > 0; place *= 10)
        countingSort(array, n, place);
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int array[n];

    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < n; i++)
        cin >> array[i];

    radixsort(array, n);

    cout << "Array after sorting:\n";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";

    return 0;
}