/* 
    You are given an array arr[], you have to re-construct an array arr[].
    The values in arr[] are obtained by doing Xor of consecutive elements in the array.

    Input : arr[ ] = {10, 11, 1, 2, 3}
    Output : 1 10 3 1 3
    
    Explanation:
    At index 0, arr[0] xor arr[1] = 1
    At index 1, arr[1] xor arr[2] = 10
    At index 2, arr[2] xor arr[3] = 3
    ...
    At index 4, No element is left So, it will remain as it is.
    New Array will be {1, 10, 3, 1, 3}.

*/

#include <bits/stdc++.h>
using namespace std;

int *PlayWithOR(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        a[i] = a[i] ^ a[i + 1];
    }
    return a;
}

int main()
{

    int n;
    cin >> n;
    int a[10000];

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    PlayWithOR(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}