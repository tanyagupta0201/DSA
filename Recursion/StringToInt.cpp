// Convert string to integer

#include <bits/stdc++.h>
using namespace std;

int StringToInt(char *a, int n)
{
    if (n == 0)
    {
        return 0;
    }

    int digit = a[n - 1] - '0'; //last digit
    int small_answer = StringToInt(a, n - 1);

    return small_answer * 10 + digit;
}

int main()
{
    char a[] = "1234";
    int len = strlen(a);

    int c = StringToInt(a, len);
    cout << c << endl;
    cout << c + 1 << endl; // Next Number

    return 0;
}