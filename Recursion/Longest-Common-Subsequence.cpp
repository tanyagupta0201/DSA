// Problem Link: https://leetcode.com/problems/longest-common-subsequence/

class Solution
{
public:
    // Recursive Approach
    int LCS(string text1, string text2, int n1, int n2)
    {
        if (n1 == 0 || n2 == 0)
            return 0;

        if (text1[n1 - 1] == text2[n2 - 1])
        {
            // Decrease the length of both the strings
            return 1 + LCS(text1, text2, n1 - 1, n2 - 1);
        }
        else
        {
            // We have choice, either decrease the length of str1 or str1
            // Take the string which returns the max one
            return max(LCS(text1, text2, n1 - 1, n2), LCS(text1, text2, n1, n2 - 1));
        }
    }

    int longestCommonSubsequence(string text1, string text2)
    {
        int n1 = text1.size();
        int n2 = text2.size();

        return LCS(text1, text2, n1, n2);
    }
};