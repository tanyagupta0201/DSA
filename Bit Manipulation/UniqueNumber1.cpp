/*
    Given a list of n numbers where all the numbers are present twice except for one number which is only present once. 
    Find the unique number without taking any extra spaces and in linear time.

    Sample Input
    7
    1 1 2 2 3 3 4 
    
    Sample Output
    4
    
    Explanation
    4 is present only once

*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, num, ans = 0;

    cout << "Enter number: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;
        ans = ans ^ num;
    }

    cout << ans << endl;

    return 0;
}