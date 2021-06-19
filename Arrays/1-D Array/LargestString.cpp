// Read N, followed by N strings and print the largest string and its length.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len = 0, largest_len = 0, n;
    char a[100], largest[100];
    cout << "How many strings do you want to enter ??" << endl;
    cin >> n;
    cin.get();

    cout << "Enter all the strings: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin.getline(a, 100);
        len = strlen(a);
        if (len > largest_len)
        {
            largest_len = len;
            strcpy(largest, a);
        }
    }
    cout << "The largest string is: " << largest << " and its length is: " << largest_len;
    return 0;
}