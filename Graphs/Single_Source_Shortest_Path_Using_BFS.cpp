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
        map<T, int> distance;
        queue<T> q;

        // All other nodes will have int_max
        for (auto node_pair : l) // node_pair stores node number and its list
        {
            T node = node_pair.first;
            distance[node] = INT_MAX;
        }

        // Except source node all other nodes have infinite distance
        q.push(source);
        distance[source] = 0;

        while (!q.empty())
        {
            T node = q.front();
            q.pop();

            for (auto nbr : l[node])
            {
                if (distance[nbr] == INT_MAX)
                {
                    q.push(nbr);
                    distance[nbr] = distance[node] + 1;
                }
            }
        }

        // Print the distance to every node
        for (auto node_pair : l)
        {
            T node = node_pair.first;
            int d = distance[node];
            cout << "Node " << node << " Distance from source " << d << endl;
        }
    }
};

int main()
{
    Graph<int> g;

    g.AddEdge(0, 1);
    g.AddEdge(0, 3);
    g.AddEdge(1, 2);
    g.AddEdge(3, 2);
    g.AddEdge(3, 4);

    g.bfs(0);
    return 0;
}