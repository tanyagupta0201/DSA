// Problem Link: https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/0/?category[]=Graph&page=1&query=category[]Graphpage1

class Solution
{
public:
    // Function to find if the given edge is a bridge in graph.
    vector<pair<int, int>> v;

    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], vector<int> &disc, vector<int> &low, int &timer)
    {
        vis[node] = 1;
        disc[node] = low[node] = timer++;

        for (auto nbr : adj[node])
        {
            if (nbr == parent)
                continue;

            if (!vis[nbr])
            {
                dfs(nbr, node, vis, adj, disc, low, timer);
                low[node] = min(low[node], low[nbr]);

                if (low[nbr] > disc[node])
                {
                    v.push_back({node, nbr});
                }
            }
            else
            {
                // if visited
                low[node] = min(low[node], disc[nbr]);
            }
        }
    }

    int isBridge(int n, vector<int> adj[], int c, int d)
    {
        // Code here
        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<int> vis(n, 0);
        int timer = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, vis, adj, disc, low, timer);
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            auto it = v[i];

            if ((it.first == c && it.second == d) || (it.first == d && it.second == c))
            {
                return true;
            }
        }
        return false;
    }
};