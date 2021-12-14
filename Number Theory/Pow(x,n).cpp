// Problem Link: https://leetcode.com/problems/powx-n/

/*  Brute Force:
    Traverse from 1 to n and do ans = ans * n (ans is taken in double)
    If n is negative then ans = 1 / ans

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

/* Optimal Approach */
// Time Complexity: O(log n)(base 2) (As 2 is being divided again and again)

class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1.0;

        // long long is taken to prevent integer overflow
        long long num = n;

        // Making negative number as positive
        if (num < 0)
        {
            num = num * -1;
        }

        while (num)
        {
            if (num % 2 == 0)
            {
                x = x * x;
                num = num / 2;
            }
            else
            {
                ans *= x;
                num = num - 1;
            }
        }

        if (n < 0)
        {
            ans = (double)(1.0) / (double)(ans);
        }

        return ans;
    }
};