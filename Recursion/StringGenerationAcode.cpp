#include <bits/stdc++.h>
using namespace std;

void generate_strings(char *in, char *out, int i, int j)
{
    // Base Case
    if (in[i] == '\0')
    {
        out[i] = '\0';
        cout << out << endl;
        return;
    }

    // Recursive Case
    // One digit at a time
    int digit = in[i] - '0';
    char ch = digit + 'A' - 1;
    out[j] = ch;
    generate_strings(in, out, i + 1, j + 1);

    // Two digit at a time
    if (in[i + 1] != '\0')
    {
        int SecondDigit = in[i + 1] - '0';
        int no = digit * 10 + SecondDigit;
        if (no <= 26)
        {
            ch = no + 'A' - 1;
            out[j] = ch;
            generate_strings(in, out, i + 2, j + 1);
        }
    }
    return;
}

int main()
{
    char in[100], out[100];
    cout << "Enter the number: ";
    cin >> in;
    generate_strings(in, out, 0, 0);
    return 0;
}