// Problem Link: https://leetcode.com/problems/plus-one/

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int index = digits.size() - 1;

        while (index >= 0)
        {
            if (digits[index] == 9)
            {
                digits[index] = 0;
                index--;
            }
            else
            {
                digits[index] += 1;
                return digits;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};