// Recursive function to multiply 2 numbers without using * operator

#include <bits/stdc++.h>
using namespace std;

int multiply(int a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    return a + multiply(a, b - 1);
}
int main()
{
    int a, b;
    cout << "Enter 2 Numbers: " << endl;
    cin >> a >> b;
    cout << multiply(a, b) << endl;
    return 0;
}