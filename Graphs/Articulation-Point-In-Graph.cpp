// Problem Link: https://practice.geeksforgeeks.org/problems/articulation-point-1/0/

class Solution
{
public:
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &low, vector<int> &disc, vector<int> &arti, int timer)
    {
        vis[node] = 1;
        low[node] = disc[node] = timer++;
        int child = 0;

        for (auto it : adj[node])
        {
            if (it == parent)
                continue;

            if (!vis[it])
            {
                dfs(it, node, adj, vis, low, disc, arti, timer);
                low[node] = min(low[node], low[it]);

                if (low[it] >= disc[node] && parent != -1)
                {
                    arti[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], disc[it]);
            }
        }

        if (parent == -1 && child > 1)
        {
            arti[node] = 1;
        }
    }

    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        vector<int> vis(n, 0);
        vector<int> low(n, -1), disc(n, -1);
        vector<int> arti(n, 0);
        int timer = 0;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, -1, adj, vis, low, disc, arti, timer);
            }
        }

        int cnt = 0;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            if (arti[i] == 1)
            {
                ans.push_back(i);
                cnt++;
            }
        }

        if (cnt == 0)
        {
            return {-1};
        }

        return ans;
    }
};
