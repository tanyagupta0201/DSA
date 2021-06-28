// Graph Traversal - Depth First Search(DFS)

#include <iostream>
#include <map>
#include <queue>
#include <list>
using namespace std;

template <typename T>
class Graph
{
    // Considering the graph to be unweighted and bidirectional
    map<T, list<T>> l;

public:
    void AddEdge(int x, int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T source, map<T, bool> &Visited) // Value is passed by reference as we do not want to make a copy and it remains same everywhere
    {
        // Recursive function that will traverse the graph
        cout << source << " ";
        Visited[source] = true;

        // Go to all the neighbours of the node that is not visited one by one
        for (T nbr : l[source])
        {
            if (!Visited[nbr])
            {
                dfs_helper(nbr, Visited);
            }
        }
    }

    void dfs(T source)
    {
        map<T, bool> Visited;

        // In the beginning, mark all the nodes as unvisited
        for (auto p : l)
        {
            T node = p.first;
            Visited[node] = false;
        }
        // Call the helper function
        dfs_helper(source, Visited);
    }
};

int main()
{
    Graph<int> g;

    g.AddEdge(0, 1);
    g.AddEdge(1, 2);
    g.AddEdge(2, 3);
    g.AddEdge(3, 4);
    g.AddEdge(4, 5);

    g.dfs(0);
    return 0;
}