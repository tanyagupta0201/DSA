/*
    Input : arr1[] = {1, 3, 4, 5, 7}
            arr2[] = {2, 3, 5, 6} 

    Output : Union : {1, 2, 3, 4, 5, 6, 7}

*/

#include <bits/stdc++.h>
using namespace std;

void union_of_arrays(int a[], int b[], int n1, int n2)
{
    // Sets are ordered and unique
    set<int> s;

    for (int i = 0; i < n1; i++)
    {
        s.insert(a[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        s.insert(b[i]);
    }
    
    cout << "Union of arrays: ";
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *(it) << ", ";
    }
    cout << endl;
}

int main()
{
    int a[] = {1, 6, 8, 9, 11};
    int n1 = sizeof(a) / sizeof(int);

    int b[] = {1, 2, 3, 4, 5, 9, 11, 11, 15, 19};
    int n2 = sizeof(b) / sizeof(int);

    union_of_arrays(a, b, n1, n2);
    return 0;
}
