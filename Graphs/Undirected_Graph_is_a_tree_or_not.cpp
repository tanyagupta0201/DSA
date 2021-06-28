#include <bits/stdc++.h>
using namespace std;

// Check if an undirected graph is a tree or not
// If there is a cycle present in the graph then it is not a tree

class Graph
{
    list<int> *l;
    int V;

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void AddEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool isTree()
    {
        bool *visited = new bool[V];
        int *parent = new int[V];

        queue<int> q;

        for (int i = 0; i < V; i++)
        {
            visited[i] = false;
            parent[i] = i;
        }

        int source = 0;

        q.push(source);
        visited[source] = true;

        // Pop out one node and visit its neighbours
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int nbr : l[node])
            {
                if (visited[nbr] == true and parent[node] != nbr)
                {
                    return false;
                }
                else if (!visited[nbr])
                {
                    visited[nbr] = true;
                    parent[nbr] = node;
                    q.push(nbr);
                }
            }
        }
        return true;
    }
};

int main()
{
    Graph g(4);

    g.AddEdge(0, 1);
    g.AddEdge(3, 2);
    g.AddEdge(1, 2);
    g.AddEdge(0, 3);

    if (g.isTree())
    {
        cout << "YES, it is a tree !!" << endl;
    }
    else
    {
        cout << "NO, it is not a tree !!" << endl;
    }

    return 0;
}