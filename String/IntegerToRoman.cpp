// https://leetcode.com/problems/integer-to-roman/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num)
    {
        int intCode[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string code[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

        string s;
        for (int i = 0; i < 13; ++i)
        {
            while (num >= intCode[i])
            {
                s.append(code[i]);
                num -= intCode[i];
            }
        }
        return s;
    }
};
