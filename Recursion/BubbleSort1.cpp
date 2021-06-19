#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n)
{
    // Base Case
    if (n == 1)
    {
        return;
    }

    // Rec Case
    for (int j = 0; j < n - 1; j++)
    {
        if (a[j] > a[j + 1])
        {
            swap(a[j], a[j + 1]);
        }
    }
    bubbleSort(a, n - 1);
    return;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[20];
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    bubbleSort(a, n);

    cout << "The sorted Array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}