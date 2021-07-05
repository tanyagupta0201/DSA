#include <bits/stdc++.h>
using namespace std;

class Graph
{
    // Adjacency List
    vector<pair<int, int>> *l;
    int V;

public:
    Graph(int n)
    {
        V = n;
        l = new vector<pair<int, int>>[n];
    }

    void AddEdge(int x, int y, int w)
    {
        l[x].push_back({y, w});
        l[y].push_back({x, w});
    }

    int prims()
    {
        // Initialize a min Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;

        // Another Array
        // Visited Array that denotes whether a node has been included in MST or not
        bool *visited = new bool[V]{0};
        int ans = 0;

        // Begin
        Q.push({0, 0}); // Weight, Node

        while (!Q.empty())
        {
            // Pick out the edge with min weight
            auto best = Q.top();
            Q.pop();

            int to = best.second;
            int weight = best.first;

            if (visited[to])
            {
                // Discard the edge and continue
                continue;
            }

            // Otherwise take the current edge
            ans += weight;
            visited[to] = 1;

            // Add the new edges in the queue
            for (auto x : l[to])
            {
                if (visited[x.first] == 0)
                {
                    Q.push({x.second, x.first});
                }
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

    cout << g.prims() << endl;
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