#include <bits/stdc++.h>
using namespace std;

void subsets(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = s[0];
    string rest_of_the_string = s.substr(1);

    subsets(rest_of_the_string, ans);
    subsets(rest_of_the_string, ans + ch);
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    subsets(s, "");
    return 0;
}