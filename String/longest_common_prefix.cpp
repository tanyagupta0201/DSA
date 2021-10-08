// https://leetcode.com/problems/longest-common-prefix/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int a[strs.size()];
        if (strs.size() == 1)
            return strs[0];
        for (int i = 0; i < strs.size(); i++)
            a[i] = strs[i].size();
        int min = *min_element(a, a + strs.size());
        string s = "";
        int i, j, c = 0;
        for (i = 0; i < min; i++)
        {
            c = 0;
            for (j = 0; j < strs.size() - 1; j++)
            {
                if (strs[j][i] == strs[j + 1][i])
                    c++;
            }
            if (c == strs.size() - 1)
                s = s + strs[j - 1][i];
            else
                break;
        }
        return s;
    }
};