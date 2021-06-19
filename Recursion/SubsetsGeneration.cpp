#include <bits/stdc++.h>
using namespace std;

void GenerateSubsets(char *inp, char *out, int i, int j)
{
    // Base Case
    if (inp[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // Rec Case
    // Include the current character
    out[j] = inp[i];
    GenerateSubsets(inp, out, i + 1, j + 1);

    // Exclude the current character
    GenerateSubsets(inp, out, i + 1, j);
}

int main()
{
    char input[20];
    cout << "Enter the string: ";
    cin >> input;
    char output[30];
    GenerateSubsets(input, output, 0, 0);
    return 0;
}