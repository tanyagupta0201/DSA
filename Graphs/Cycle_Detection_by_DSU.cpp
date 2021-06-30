#include <bits/stdc++.h>
using namespace std;

// Cycle Detection in an undirected graph using DSU
class Graph
{
    int V;
    list<pair<int, int>> l;

public:
    Graph(int V)
    {
        this->V = V;
    }

    void AddEdge(int u, int v)
    {
        l.push_back(make_pair(u, v));
    }

    // Find
    int FindSet(int i, int parent[])
    {
        // Base Case
        if (parent[i] == -1)
        {
            return i;
        }
        return FindSet(parent[i], parent);
    }

    // Union
    void Union_Set(int x, int y, int parent[])
    {
        int s1 = FindSet(x, parent);
        int s2 = FindSet(y, parent);

        if (s1 != s2)
        {
            parent[s1] = s2;
        }
    }

    bool ContainsCycle()
    {
        // DSU Logic to check if the graph contains cycle or not
        int *parent = new int[V];

        for (int i = 0; i < V; i++)
        {
            parent[i] = -1;
        }

        // Iterate over the edge list
        for (auto edge : l)
        {
            int i = edge.first;
            int j = edge.second;

            int s1 = FindSet(i, parent);
            int s2 = FindSet(j, parent);

            if (s1 != s2)
            {
                Union_Set(s1, s2, parent);
            }
            else
            {
                cout << "Same Parents " << s1 << " and " << s2 << endl;
                return true;
            }
        }
        delete[] parent;
        return false;
    }
};

int main()
{
    Graph g(4);

    g.AddEdge(0, 1);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 0);

    cout << g.ContainsCycle() << endl;
    // 1 means there is a cycle
    // 0 means there is no cycle
    return 0;
}