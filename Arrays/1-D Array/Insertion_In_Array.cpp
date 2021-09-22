#include <bits/stdc++.h>
using namespace std;

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int insert(int *a, int n, int index, int ele)
{
    if (index > n)
    {
        return -1;
    }

    for (int i = n - 1; i >= index; i--)
    {
        a[i + 1] = a[i];
    }

    a[index] = ele;
    return 1;
}

int main()
{
    int n;
    cin >> n;

    int a[100];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int index, ele;

    cout << "Enter the element to be inserted: ";
    cin >> ele;

    cout << "Enter the position at which you want to insert: ";
    cin >> index;

    insert(a, n, index, ele);

    n = n + 1;
    display(a, n);
    return 0;
}