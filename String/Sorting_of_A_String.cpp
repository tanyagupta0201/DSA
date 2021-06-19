// Sorting of a string in a list

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "How many strings do you want to enter?" << endl;
    cin >> n;
    cin.get();
    string s[100];
    cout << "Enter the strings: " << endl;
    for (int i = 0; i < n; i++)
    {
        getline(cin, s[i]);
    }
    cout << endl;

    sort(s, s + n); // It sorts in lexicographically

    cout << "After sorting: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << endl;
    }

    return 0;
}