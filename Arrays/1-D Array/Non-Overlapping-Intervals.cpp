// https://leetcode.com/problems/non-overlapping-intervals/discuss/1157602/Easy-C%2B%2B-solution-with-drawing
//10 11 11 <= <= >

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(), intervals.end());
        
        int n = intervals.size();
        int l = 0, r = 1;
        int cnt = 0;
        
        while(r < n)
        {
            // case 1 - non overlapping
            if(intervals[l][1] <= intervals[r][0])
            {
                l = r;
                r++;
            }
            
            // case 2
            else if(intervals[l][1] <= intervals[r][1])
            {
                cnt++;
                r++;
            }
            
            // case 3
            else if(intervals[l][1] > intervals[r][1])
            {
                cnt++;
                l = r;
                r++;
            }
            
        }
        
        return cnt;
    }
};
