//Recursive function in which all duplicate consecutive characters are separated by a '*'.
// Example: hello = hel*lo

#include <bits/stdc++.h>
using namespace std;

void Duplicate(char a[], int i)
{
    //Base Case
    if (a[i] == '\0' or a[i + 1] == '\0')
    {
        return;
    }

    if (a[i] == a[i + 1])
    {
        int j = i + 1;

        //Take j to the end of the array
        while (a[j] != '\0')
        {
            j++;
        }

        //Shifting from right to left
        while (j >= i + 1)
        {
            a[j + 1] = a[j];
            j--;
        }

        //Replacement + Recursive call for remaining part
        a[i + 1] = '*';
        Duplicate(a, i + 1);
    }
    else
    {
        //Go to the next position
        Duplicate(a, i + 1);
    }
    return;
}
int main()
{

    char a[10001];
    cout << "Enter the string: ";
    cin >> a;

    Duplicate(a, 0);
    cout << a << endl;
    return 0;
}