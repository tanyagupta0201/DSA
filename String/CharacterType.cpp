// Write a code which inputs a character and returns "U" if it is a upperCase character, "L" if it is LoweCase character else return l.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    cin >> ch;

    if (isupper(ch))
    {
        cout << "U" << endl;
    }
    else if (islower(ch))
    {
        cout << "L" << endl;
    }
    else
    {
        cout << "l" << endl;
    }

    return 0;
}