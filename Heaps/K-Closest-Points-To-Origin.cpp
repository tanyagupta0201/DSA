// Problem Link: https://leetcode.com/problems/k-closest-points-to-origin/

class Solution
{
public:
    double Distance(vector<int> p)
    {
        return sqrt(pow(p[0], 2) + pow(p[1], 2));
    }

    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        vector<vector<int>> ans;

        priority_queue<pair<double, vector<int>>> pq; // max heap, as we want min distance {dis, points}

        for (vector<int> p : points)
        {
            pq.push({Distance(p), {p[0], p[1]}});

            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};