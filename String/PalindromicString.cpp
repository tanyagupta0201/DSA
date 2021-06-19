// To check if the inputted string is palindromic or not

#include <bits/stdc++.h>
using namespace std;

bool IsPalindrome(char a[])
{
    int l = strlen(a);
    int i = 0, j = l - 1;
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
    char a[100];
    cout << "Enter the string: ";
    cin.getline(a, 100);

    IsPalindrome(a);

    if (IsPalindrome(a))
    {
        cout << "Palindromic String !!";
    }
    else
    {
        cout << "Not a Palindromic String !!";
    }
    return 0;
}