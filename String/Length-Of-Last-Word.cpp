// Problem Link: https://leetcode.com/problems/length-of-last-word/

class Solution
{
public:
    int lengthOfLastWord(string s)
    {

        if (s.length() == 1)
            return 1;

        int c = 0;

        int n = s.length();

        while (n > 0)
        {
            // as n - 1 is the valid index
            if (s[--n] != ' ')
            {
                c++;
            }
            else if (c > 0)
            {
                return c;
            }
        }
        return c;
    }
};