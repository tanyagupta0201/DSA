// Recursive function to perform power (a,n)
// Example: a = 2, n = 3, power = 2 ^ 3 = 8

#include <bits/stdc++.h>
using namespace std;

int power(int a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    return a * power(a, n - 1);
}
int main()
{
    int a, n;
    cout << "Enter value of a: ";
    cin >> a;
    cout << "Enter value of n: ";
    cin >> n;
    cout << power(a, n) << endl;
    return 0;
}