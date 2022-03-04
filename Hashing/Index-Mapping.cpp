#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// 0 -> positive, 1 -> negative
// Since array is global, it is initialized as 0.
int h[MAX + 1][2];

bool search(int x)
{
    // Positive number
    if (x >= 0)
    {
        if (h[x][0] == 1)
            return true;
        else
            return false;
    }

    // Negative number'
    x = abs(x);
    if (h[x][1] == 1)
        return true;
    else
        return false;
}

void insert(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        {
            h[arr[i]][0] = 1;
        }
        else
        {
            h[abs(arr[i])][1] = 1;
        }
    }
}

int main()
{
    int arr[] = {1, 9, -7, 8, -13, -11, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    insert(arr, n);

    int x;
    cout << "Enter the element to be searched: ";
    cin >> x;

    if (search(x))
    {
        cout << "Present!" << endl;
    }
    else
    {
        cout << "Not Present!" << endl;
    }

    return 0;
}
