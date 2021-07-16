/*
    Input : arr1[] = {1, 3, 4, 5, 7}
            arr2[] = {2, 3, 5, 6} 

    Output : Intersection : {3, 5}

*/

#include <bits/stdc++.h>
using namespace std;

void intersection_of_arrays(int a[], int b[], int n1, int n2)
{
    int i = 0, j = 0;
    set<int> s;

    while (i < n1 and j < n2)
    {
        if (a[i] == b[j])
        {
            s.insert(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    cout << "Intersection of arrays: ";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *(it) << ", ";
    }
}

int main()
{
    int a[] = {1, 8, 9, 6, 7, 11};
    int n1 = sizeof(a) / sizeof(int);

    int b[] = {1, 2, 3, 4, 5, 9, 11, 3, 11, 15, 19};
    int n2 = sizeof(b) / sizeof(int);

    sort(a, a + n1);
    sort(b, b + n2);

    intersection_of_arrays(a, b, n1, n2);
    return 0;
}