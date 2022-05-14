/*
    We are n, m where n = number of nodes and e = number of edges
    Then we are given u, v where there is a edge between u and v
    Considering 1 based indexing.
*/

// Method 1 : Using Adjacent matrix
// This works only for smaller inputs
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // declare adjacent matrix
    int adj[n + 1][m + 1];

    // take edge as input
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // Mark that position as visited
        // There exists an edge between u and v
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

// Method 2 : Using Adjacency List

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    // declare adjacency list
    vector<int> adj[n + 1];

    // Undirected Unweighted graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // There exists an edge between u and v
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Directed Unweighted graph
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        // There exists an edge from u and v
        adj[u].push_back(v);
    }

    // Undirected weighted graph
    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    return 0;
}