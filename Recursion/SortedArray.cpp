// Recursive function to check if the given array is sorted or not
// In boolean 1 -> True and 0 -> False

#include <bits/stdc++.h>
using namespace std;

bool isSorted(int a[], int n)
{
    if (n == 0 or n == 1)
    {
        return true;
    }

    if (a[0] <= a[1] and isSorted(a + 1, n - 1))
    {
        return true;
    }
    return false;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int a[100];
    cout << "Enter the array elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << isSorted(a, n);
    return 0;
}