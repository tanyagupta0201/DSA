// BRUTE FORCE APPROACH

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        vector<vector<int>> mergedIntervals;
         
        intervals.push_back(newInterval);
        
        
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


// EFFICIENT

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) 
    {
        int i = 0;
        vector<vector<int>> ans;
        
        // CASE 1: Left Part (no intersection with new interval)
        while(i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }

        // CASE 2: newInterval Part (merge or without merge)
        while(i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            
            i++;
        }
        
        ans.push_back(newInterval);

        // CASE 3: Right Part (no intersection with new interval)
        while(i < intervals.size() && intervals[i][0] > newInterval[1])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        
        return ans;        
    }
};
