// Graph Traversal - Breadth First Search(BFS)

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

    void bfs(T source)
    {
        map<T, int> visited;
        queue<T> q;

        q.push(source);
        visited[source] = true;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();
            cout << node << " ";

            for (auto nbr : l[node])
            {
                if (!visited[nbr])
                {
                    q.push(nbr);
                    // Mark that neighbour as visited
                    visited[nbr] = true;
                }
            }
        }
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

    g.bfs(0);
    return 0;
}