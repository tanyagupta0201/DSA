#include <bits/stdc++.h>
using namespace std;

void CountSort(int *a, int n)
{
    int largest = INT_MIN;

    // Largest number from the array assuming all the numbers are greater than 0
    for (int i = 0; i < n; i++)
    {
        largest = max(largest, a[i]);
    }

    // Creating a frequency array
    int *freq = new int[largest + 1]{0};

    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    // Put the elements back into the array after reading from frequency array
    int j = 0;
    for (int i = 0; i <= largest; i++)
    {
        while (freq[i] > 0)
        {
            a[j] = i;
            j++;
            freq[i]--;
        }
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

    CountSort(a, n);
    cout << "Array after sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}