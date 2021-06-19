//Find the maximum and the minimum element from the given array

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a[20];
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int largest = INT_MIN;
    int smallest = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > largest)
        {
            largest = a[i];
        }
        else if (a[i] < smallest)
        {
            smallest = a[i];
        }
    }

    cout << "The largest element is: " << largest << endl;
    cout << "The smallest element is: " << smallest << endl;

    return 0;
}