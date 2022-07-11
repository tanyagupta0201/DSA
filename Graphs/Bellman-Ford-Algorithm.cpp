// Problem Link: https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1/#

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*  Function to implement Dijkstra
     *   adj: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */
    vector<int> bellman_ford(int n, vector<vector<int>> adj, int src)
    {
        vector<int> disc(n, 1e8);
        disc[src] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            for (auto it : adj)
            {
                // int u = it[0];
                // int v = it[1];
                // int wt = it[2];

                if (disc[it[0]] + it[2] < disc[it[1]])
                {
                    disc[it[1]] = disc[it[0]] + it[2];
                }
            }
        }

        int flag = 0;
        // check if there is negative cycle
        for (auto it : adj)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if (disc[u] + wt < disc[v]) // negative cycle
            {
                flag = 1;
                break;
            }
        }

        return disc;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.bellman_ford(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}