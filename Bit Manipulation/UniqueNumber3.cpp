/*
    We are given an array containg n numbers. 
    All the numbers are present thrice except for one number which is only present once. 
    Find the unique number. 

    Sample Input
    7
    1 1 1 2 2 2 3

    Sample Output
    3
    
    Explanation
    3 is present only once
    
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, no;
    cin >> n;
    // Array of fixed size - O(1) space
    int cnt[64] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> no;
        // Update the cnt array by extracting bits
        int j = 0;
        while (no > 0)
        {
            int last_bit = (no & 1);
            cnt[j] += last_bit;
            j++;
            no = no >> 1;
        }
    }

    // Iterate over the array and form the answer by converting 0s and 1s into a number
    int p = 1;
    int ans = 0;
    for (int i = 0; i < 64; i++)
    {
        cnt[i] %= 3;
        ans += (cnt[i] * p);
        p = p << 1;
    }

    // Print the final answer
    cout << ans << endl;

    return 0;
}