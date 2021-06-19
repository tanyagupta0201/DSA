#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ele, a[50];
    cout << "Enter the size of the array: ";
    cin >> n;
    cout << "Enter the element to be searched: ";
    cin >> ele;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] == ele)
        {
            cout << "Element found at index " << i << endl;
        }
    }
    return 0;
}