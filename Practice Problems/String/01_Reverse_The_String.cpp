#include <bits/stdc++.h>
using namespace std;

void Reverse(char s[], int len)
{
    int start = 0, end = len - 1;
    while (start < end)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}

int main()
{
    char s[100];
    cin.getline(s, 100);

    int len = strlen(s);

    Reverse(s, len);
    cout << s << endl;
    return 0;
}