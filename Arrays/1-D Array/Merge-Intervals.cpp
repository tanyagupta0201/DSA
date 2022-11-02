// Time Complexity: O(NlogN) + O(N). O(NlogN) for sorting and O(N) for traversing through the array.

// Space Complexity: O(N) to return the answer of the merged intervals.


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> mergedIntervals;
        
        if(intervals.size() == 0)
            return mergedIntervals;
        
        sort(intervals.begin(), intervals.end());
        
        vector<int> tempInterval = intervals[0];
        
        for(auto it: intervals)
        {
            if(it[0] <= tempInterval[1])
            {
                tempInterval[1] = max(it[1], tempInterval[1]);
            }
            else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval = it;
            }
        }
        
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};
