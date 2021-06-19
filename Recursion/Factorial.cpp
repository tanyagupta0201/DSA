// Recursive function to find the factorial of a number

#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * fact(n - 1);
}
int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    cout << "The factorial of the number: " << fact(n) << endl;
    return 0;
}