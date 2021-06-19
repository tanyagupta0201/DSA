// Remove duplicate consecutive characters from a string
// Example: cooodiinng -> coding

#include <bits/stdc++.h>
using namespace std;

void RemoveDuplicates(char a[])
{
    int len = strlen(a);
    int prev = 0;
    for (int curr = 1; curr < len; curr++)
    {
        if (a[prev] != a[curr])
        {
            prev++;
            a[prev] = a[curr];
        }
    }
    a[prev + 1] = '\0';
    return;
}

int main()
{
    char a[100];
    cout << "Enter the string: ";
    cin >> a;
    RemoveDuplicates(a);
    cout << a << endl;
    return 0;
}