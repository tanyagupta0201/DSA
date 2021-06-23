/* Take as input S, a string. Write a program that inserts between each pair of characters the difference between their ascii codes and 
    print the ans.

    Sample Input: acb
    Sample Output: a2c-1b
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    int i;
    getline(cin, s);

    for (i = 1; i < s.length(); i++)
    {
        // i-1,i
        cout << s[i - 1] << (s[i] - s[i - 1]);
    }
    cout << s[i - 1] << endl;
}