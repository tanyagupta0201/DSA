#include <bits/stdc++.h>
using namespace std;

bool IsPalindrome(int a[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (a[i] == a[j])
        {
            i++;
            j--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if (IsPalindrome(a, n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}