// Find all possible combinations of words formed from the mobile keypad with some digits associated with each key.

#include <bits/stdc++.h>
using namespace std;

void Generate_Names(char *in, char *out, int i, int j)
{
    char Keypad[][10] = {"", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};

    // Base Case
    if (in[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // Recursive Case
    int digit = in[i] - '0';

    if (digit == 1 || digit == 0)
    {
        Generate_Names(in, out, i + 1, j);
    }

    for (int k = 0; Keypad[digit][k] != '\0'; k++)
    {
        out[j] = Keypad[digit][k];
        // Fill the remaining part
        Generate_Names(in, out, i + 1, j + 1);
    }
    return;
}

int main()
{
    char in[100], out[100];
    cout << "Enter the number: ";
    cin >> in;
    Generate_Names(in, out, 0, 0);
    return 0;
}