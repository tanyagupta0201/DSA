#include <bits/stdc++.h>
using namespace std;

int main()
{
    int b[100];
    cout << sizeof(b) << endl; // Returns the amount of memory taken by all the elements
    cout << b << endl;         // Will return the address of the first element of the array

    int n;
    cout << "Enter the size of the array: " << endl;
    cin >> n;
    int *a = new int[n];
    cout << sizeof(a) << endl; // Here a is treated as a pointer so it will return the size of the pointer
    cout << a << endl;         // Will return the address of the first element of the array

    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {

        cout << a[i] << " ";
    }

    delete[] a; // Free up space

    return 0;
}