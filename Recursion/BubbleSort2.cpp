#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int j, int n)
{
    // Base Case
    if (n == 1)
    {
        return;
    }

    if (j == n - 1)
    {
        // Single pass of the current array has been done
        return bubbleSort(a, 0, n - 1);
    }

    // Rec Case
    if (a[j] > a[j + 1])
    {
        swap(a[j], a[j + 1]);
    }
    bubbleSort(a, j + 1, n);
    return;
}

int main()
{
    int n, j = 0;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[20];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bubbleSort(a, j, n);

    cout << "The sorted Array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}