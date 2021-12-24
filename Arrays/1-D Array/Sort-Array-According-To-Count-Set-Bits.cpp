// Problem Link: https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#

class Solution
{
public:
    bool comp(int a, int b)
    {
        int c1 = 0, c2 = 0;

        while (a > 0)
        {
            a = a & (a - 1);
            c1++;
        }

        while (b > 0)
        {
            b = b & (b - 1);
            c2++;
        }

        if (c1 != c2)
        {
            return c1 > c2;
        }
        return a < b;
    }

    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr + n, comp);
    }
};