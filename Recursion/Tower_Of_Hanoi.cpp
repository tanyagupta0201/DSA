// Tower Of Hanoi

#include <iostream>
using namespace std;

void TOH(int n, char src, char helper, char dest)
{
    // Base Case
    if (n == 0)
    {
        return;
    }

    // Recursive Case
    if (n >= 1)
    {
        TOH(n - 1, src, dest, helper);
        cout << "Moving ring " << n << " from " << src << " to " << dest << endl;
        TOH(n - 1, helper, src, dest);
    }
}

int main()
{
    int n;
    cin >> n;
    TOH(n, 'A', 'B', 'C');
    return 0;
}