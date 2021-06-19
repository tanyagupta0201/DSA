#include <bits/stdc++.h>
using namespace std;

int setbit(int n, int i)
{
    int mask = 1 << i;
    int ans = n | mask;
    return ans;
}
int main()
{
    int n, i;
    cout << "Enter The Number: ";
    cin >> n;
    cout << "Enter the value of i: ";
    cin >> i;
    n = setbit(n, i);
    cout << "Answer " << n << endl;
    return 0;
}