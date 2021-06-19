#include <bits/stdc++.h>
using namespace std;

char words[][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printWords(int n)
{
    //Base Case
    if (n == 0)
    {
        return;
    }

    //Rec Case
    printWords(n / 10);
    int digit = n % 10;
    cout << words[digit] << " ";
    return;
}
int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    printWords(n);
    return 0;
}