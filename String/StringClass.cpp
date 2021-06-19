// Some basic functions of string

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Ways of initializing and copying strings
    string s0;
    string s1("Hello Friends!!");
    string s2 = "Hello World !!";
    string s3(s1);
    string s4(s2);
    string s5 = s1;
    char a[] = {'T', 'a', 'n', 'y', 'a', '\0'};
    string s6 = a;
    string s7(a);

    cout << s0 << endl;
    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
    cout << s6 << endl;
    cout << s7 << endl;

    // Empty function
    if (s0.empty())
    {
        cout << "s0 is an empty string !!" << endl;
    }

    // Append Function
    s1.append(" I love coding. "); // 1st way to append
    cout << s1 << endl;
    s1 += "C++ is my favourite language."; // 2nd way to append
    cout << s1 << endl;
    cout << s6.append(s7) << endl;

    // Remove function
    s6.clear();
    cout << s6 << endl;

    // Comparing 2 strings
    // compare() function returns 0 if both the strings are equal else it returns positive or negative values(lexigraphically)

    s0 = "Mango";
    s1 = "Apple";
    cout << s1.compare(s0) << endl;

    s0 = "pine apple";
    s1 = "pine apple";
    cout << s0.compare(s1) << endl;

    s0 = "Grapes";
    s1 = "Oranges";
    cout << s0.compare(s1) << endl;
    // Overloaded Operator Operators
    if (s0 > s1)
    {
        cout << "Grapes are lexi greater than oranges." << endl;
    }
    else
    {
        cout << "Oranges are lexi greater than grapes." << endl;
    }

    // Finding Substrings
    string s = "I love my country India.";
    int index = s.find("country");
    cout << index << endl;

    // Remove a word from the string
    string word = "country";
    int len = word.length();
    cout << s << endl;
    s.erase(index, len + 1);
    cout << s << endl;

    // Iterate over all characters of the string
    for (int i = 0; i < s7.length(); i++)
    {
        cout << s7[i] << ":";
    }
    cout << endl;

    // Iterators
    // auto automaticaaly defines the datatype
    for (auto it = s2.begin(); it != s2.end(); it++)
    {
        cout << (*it) << ",";
    }
    cout << endl;

    // Way to iterate without using auto
    for (string::iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << (*it) << ",";
    }
    cout << endl;

    // For each loop
    for (char c : s2)
    {
        cout << c << ".";
    }

    return 0;
}