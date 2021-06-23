/*
aaabbccds
Output Format: The compressed String.
Sample Output: a3b2c2d1s1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int val = 1;

    getline(cin, str);
    int len = str.length();

    char prev = str[0];

    for (int i = 1; i < len; i++)
    {
        if (str[i] == prev)
        {
            val++;
        }
        else
        {
            cout << str[i - 1] << val;
            val = 1;
        }
        prev = str[i];
    }
    cout << prev << val << endl;

    return 0;
}