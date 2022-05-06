// Problem Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
    string removeDuplicates(string s) 
    {
        stack<char> st;
        
        for(int i = 0; i < s.size(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(st.top() == s[i])
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        
        string str;
        
        while(!st.empty())
        {
            str.push_back(st.top());
            st.pop();
        }
        
        reverse(str.begin(), str.end());
        
        return str;
    }
};
