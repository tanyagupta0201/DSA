#include <bits/stdc++.h>
using namespace std;

void bubbleSort(int a[], int n)
{
    int temp;

    for (int i = 0; i < n - 1; i++) //Outer Loop for number of pases
    {

        for (int j = 0; j < n - 1 - i; j++) //Inner Loop for comparisons
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

void Display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
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

    cout << "The Array before sorting: " << endl;
    Display(a, n);

    bubbleSort(a, n);

    cout << "The sorted Array is: " << endl;
    Display(a, n);

    return 0;
}