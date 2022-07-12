class Solution
{
public:
    void shortest_distance(vector<vector<int>> &adj)
    {
        int n = adj.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][j] == -1)
                {
                    adj[i][j] = INT_MAX;
                }
            }
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX && (adj[i][k] + adj[k][j] < adj[i][j]))
                    {
                        adj[i][j] = adj[i][k] + adj[k][j];
                    }
                }
            }
        }
    }
};