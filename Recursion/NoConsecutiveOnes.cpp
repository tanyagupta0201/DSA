#include <bits/stdc++.h>
using namespace std;

int NoConsecutiveOnes(char a[], int l)
{
    if (l == 1)
    {
        return 1;
    }
    return NoConsecutiveOnes(a, l - 1) + NoConsecutiveOnes(a, l - 2);
}

int main()
{
    char a[100];
    cin >> a;
    int l = strlen(a);
    cout << NoConsecutiveOnes(a, l);
    return 0;
}