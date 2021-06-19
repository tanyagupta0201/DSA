#include <bits/stdc++.h>
using namespace std;

void Generate_Brackets(char out[], int n, int index, int open, int close)
{
    // Base Case
    if (index == 2 * n)
    {
        out[index] = '\0';
        cout << out << endl;
        return;
    }

    // Rec Case
    // 2 Options
    if (open < n)
    {
        out[index] = '(';
        Generate_Brackets(out, n, index + 1, open + 1, close);
    }

    if (close < open)
    {
        out[index] = ')';
        Generate_Brackets(out, n, index + 1, open, close + 1);
    }
}

int main()
{
    int n;
    char output[100];
    cout << "Enter the number of pairs of round brackets: ";
    cin >> n;
    Generate_Brackets(output, n, 0, 0, 0);
    return 0;
}