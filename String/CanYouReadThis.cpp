/*
Sample Input: IAmACompetitiveProgrammer
Output Format: Print words present in the string, in the order in which it appears in the string.
Sample Output: I
Am
A
Competitive
Programmer
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;

    getline(cin, str);
    int len = str.length();

    for (int i = 0; i < len; i++)
    {
        if (isupper(str[i]))
        {
            cout << endl;
        }
        cout << str[i];
    }
    return 0;
}