// Insertion Sort

#include <bits/stdc++.h>
using namespace std;

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = a[i];

        while (j >= 0 and a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

int main()
{
    int n;
    cin >> n;

    int a[50];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    InsertionSort(a, n);

    cout << "The sorted array: ";
    display(a, n);

    return 0;
}