#include <bits/stdc++.h>
using namespace std;

int main()
{
    char a[100];

    cout << "Enter the sentence: ";
    cin.getline(a, 100);

    int i = 0, currLen = 0, maxLen = 0;
    int str = 0, maxstr = 0;

    while (1)
    {
        if (a[i] == ' ' or a[i] == '\0')
        {
            if (currLen > maxLen)
            {
                maxLen = currLen;
                maxstr = str;
            }
            currLen = 0;
            str = i + 1;
        }
        else
        {
            currLen++;
        }

        if (a[i] == '\0')
        {
            break;
        }

        i++;
    }

    for (int i = 0; i < maxLen; i++)
    {
        cout << a[i + maxstr];
    }

    cout << "\nLength: " << maxLen << endl;

    return 0;
}