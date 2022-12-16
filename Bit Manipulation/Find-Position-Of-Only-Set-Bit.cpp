/*

The idea is to start from the rightmost bit and one by one check value of every bit. Following is a detailed algorithm.
1) If number is power of two then and then only its binary representation contains only one ‘1’. 
   That’s why check whether the given number is a power of 2 or not. If given number is not a power of 2, then print error message and exit.
   
2) Initialize two variables; i = 1 (for looping) and pos = 1 (to find position of set bit)

3) Inside loop, do bitwise AND of i and number ‘N’. If value of this operation is true, then “pos” bit is set, so break the loop and return position. 
Otherwise, increment “pos” by 1 and left shift i by 1 and repeat the procedure. 

*/

#include <bits/stdc++.h>
using namespace std;

int countBits(int n)
{
    int c = 0;
    while (n > 0)
    {
        n = n & (n - 1);
        c++;
    }

    return c;
}

int findPosition(int n)
{
    // code here
    if (countBits(n) != 1)
        return -1;

    int pos = 1, i = 1;

    while (!(i & n))
    {
        i = i << 1;
        pos++;
    }

    return pos;
}

int main()
{
    int n;
    cout << "enter n: ";
    cin >> n;

    cout << findPosition(n) << endl;
    return 0;
}
