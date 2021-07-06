#include <bits/stdc++.h>
using namespace std;

// DSU Data Structure
// Path Compression + Union By Rank
class DSU
{
    int *parent;
    int *rank;

public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];

        // parent = -1, rank = 1
        for (int i = 0; i < n; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    // Find Function
    int find(int i)
    {
        // Base Case
        if (parent[i] == -1)
        {
            return i;
        }
        // Otherwise
        return parent[i] = find(parent[i]);
    }

    // Unite (Union)
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);

        if (s1 != s2)
        {
            // Union by rank
            if (rank[s1] < rank[s2])
            {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
            else
            {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class Graph
{
    vector<vector<int>> edgeList;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void AddEdge(int x, int y, int w)
    {
        // Weight is inserted at the first position so that sorting could be done on the basis of weight by default
        edgeList.push_back({w, x, y});
    }

    int Kruskal_MST()
    {
        // Main Logic
        // 1. Sort all the edges based upon their weights
        sort(edgeList.begin(), edgeList.end());

        // 2. Initialise a DSU
        DSU s(V);

        int ans = 0;
        for (auto edge : edgeList)
        {
            int w = edge[0];
            int x = edge[1];
            int y = edge[2];

            // 3. Take that edge in the MST which doesn't form a cycle
            if (s.find(x) != s.find(y))
            {
                s.unite(x, y);
                ans = ans + w;
            }
        }
        return ans;
    }
};

int main()
{
    // n - number of nodes, m - number of edges
    int n, m;
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++)
    {
        int x, y, w;
        cin >> x >> y >> w;
        g.AddEdge(x - 1, y - 1, w);
    }

    cout << g.Kruskal_MST() << endl;

    return 0;
}

/*

INPUT:

4 5
1 2 10
2 3 15
1 3 5
4 2 2
4 3 40

OUTPUT:
17

*/