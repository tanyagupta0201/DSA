#include <bits/stdc++.h>
using namespace std;

void ReplacePI(char a[], int i)
{
    //Base Case
    if (a[i] == '\0' or a[i + 1] == '\0')
    {
        return;
    }

    //Look for pi for current location
    if (a[i] == 'p' and a[i + 1] == 'i')
    {
        //Shifting + Replacement with 3.14
        int j = i + 2;

        //Take j to the end of the array
        while (a[j] != '\0')
        {
            j++;
        }

        //Shifting from right to left
        while (j >= i + 2)
        {
            a[j + 2] = a[j];
            j--;
        }

        //Replacement + Recursive call for remaining part
        a[i] = '3';
        a[i + 1] = '.';
        a[i + 2] = '1';
        a[i + 3] = '4';
        ReplacePI(a, i + 4);
    }
    else
    {
        //Go to the next position
        ReplacePI(a, i + 1);
    }
    return;
}
int main()
{

    char a[100];
    cout << "Enter the string: ";
    cin >> a;

    ReplacePI(a, 0);
    cout << a << endl;
    return 0;
}