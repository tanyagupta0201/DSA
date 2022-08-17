// https://youtu.be/JT1NDR-M_8A

class Solution {
public:
    // TC = O(len(s))
    int uniqueLetterString(string s) 
    {
        int n = s.size();
        
        // Character -> all its indices in the given string
        vector<vector<int>> mp(26);

        // If a character is repeating then we will make slices ie. we want only those substrings where this character occurs only once 
        // Put -1 at the starting of each character and size of the string at the end of each character
        // This will help to form a window for the characters which are at the first and the last index.
        
        // Putting -1 for all the characters
        for(int i = 0; i < 26; i++)
        {
            mp[i].push_back(-1);
        }
        
        // Store all indices
        for(int i = 0; i < n; i++)
        {
            mp[s[i] - 'A'].push_back(i);
        }
        
        // Putting the length of the string at the end of each value list
        for(int i = 0; i < 26; i++)
        {
            mp[i].push_back(n);
        }
        
        int cnt = 0;
        
        for(int i = 0; i < 26; i++)
        {
            // Traverse through all the indices of the selected character
            for(int j = 1; j < mp[i].size() - 1; j++)
            {
                // number of unique char = (no. of char in left window) * (no. of char in right window)
                cnt += (mp[i][j] - mp[i][j - 1]) * (mp[i][j + 1] - mp[i][j]);
            }
        }
        
        return cnt;        
    }
};
