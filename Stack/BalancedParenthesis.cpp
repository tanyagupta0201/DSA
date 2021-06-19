#include <bits/stdc++.h>
using namespace std;

bool IsValid(char *s)
{
    stack<char> stk;
    for (int i = 0; s[i] != '\0'; i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            stk.push(ch);
        }
        else if (ch == ')')
        {
            if (stk.empty() or stk.top() != '(')
            {
                return false;
            }
            stk.pop();
        }
    }
    return stk.empty();
}

int main()
{
    char s[100] = "((a+b) * (c +d))";
    if (IsValid(s))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}