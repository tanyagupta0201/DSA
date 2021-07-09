/*
    Given two sorted arrays. There is only 1 difference between the arrays. The first array has one element extra added in between. Find the index of the extra element.

    Examples: 

    Input:  {2, 4, 6, 8, 9, 10, 12};

            {2, 4, 6, 8, 10, 12};

    Output: 4

    Explanation: The first array has an extra element 9.

    The extra element is present at index 4.



    Input:  {3, 5, 7, 9, 11, 13}

            {3, 5, 7, 11, 13}

    Output: 3

    Explanation: The first array has an extra element 9.

    The extra element is present at index 3.
*/

#include <bits/stdc++.h>
using namespace std;

int ExtraElement(int a[], int b[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            return i;
        }
    }
    return n;
}

int main()
{
    int a[10000], b[10000];
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> b[i];
    }

    cout << ExtraElement(a, b, n) << endl;
    return 0;
}