// Write a code which inputs a character and returns "UPPERCASE" if it is a upperCase character, "lowecase" if it is LoweCase character else return "Invalid".

#include <bits/stdc++.h>
using namespace std;

int main()
{
    char ch;
    cin >> ch;

    if (isupper(ch))
    {
        cout << "UPPERCASE" << endl;
    }
    else if (islower(ch))
    {
        cout << "lowercase" << endl;
    }
    else
    {
        cout << "Invalid" << endl;
    }

    return 0;
}