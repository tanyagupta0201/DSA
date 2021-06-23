// Input a string. Print the character with maximum frequency.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int freq[256] = {0}, max = -1;
    char result;

    getline(cin, str);
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        freq[str[i]]++;
    }

    for (int i = 0; i < len; i++)
    {
        if (max < freq[str[i]])
        {
            max = freq[str[i]];
            result = str[i];
        }
    }

    cout << result << endl;
    return 0;
}