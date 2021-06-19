// Recursive function to print N numbers in  :
// for example: N = 5
// 1. Increasing order -> 1 2 3 4 5
// 2. Decreasing order -> 5 4 3 2 1

#include <bits/stdc++.h>
using namespace std;

void inc(int n)
{
    if (n == 0)
    {
        return;
    }
    inc(n - 1);
    cout << n << " ";
}

void dec(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << n << " ";
    dec(n - 1);
}
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The increasing order is: ";
    inc(n);
    cout << endl;
    cout << "The decreasing order is: ";
    dec(n);
    return 0;
}