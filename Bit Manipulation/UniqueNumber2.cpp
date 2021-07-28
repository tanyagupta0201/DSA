/*
    We are given an array containg n numbers.
    All the numbers are present twice except for two numbers which are present only once.
    Find the unique numbers in linear time without using any extra space. 

    Sample Input
    4
    3 1 2 1

    Sample Output
    2 3

    Explanation
    Smaller number comes before larger number

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int a[100005];
    cin >> n;
    int no, x = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> no;
        a[i] = no;
        x = x ^ no;
    }
    // x = a ^ b;
    int temp = x;
    int pos = 0;
    while ((temp & 1) != 1)
    {
        pos++;
        temp = temp >> 1;
    }

    // The first bit in x is at position 'pos'
    int mask = (1 << pos);

    // Find those numbers which contain set bit at pos
    int p = 0, q = 0;

    for (int i = 0; i < n; i++)
    {
        if ((a[i] & mask) > 0)
        {
            p = p ^ a[i];
        }
    }

    q = x ^ p;
    cout << min(p, q) << " " << max(p, q) << endl;

    return 0;
}
