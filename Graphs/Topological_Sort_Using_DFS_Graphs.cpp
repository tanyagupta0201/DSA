#include <iostream>
#include <map>
#include <queue>
#include <list>
#include <string>
#include <cstring>
using namespace std;

template <typename T>
class Graph
{
    // Considering the graph to be unweighted and bidirectional
    map<T, list<T>> l;

public:
    void AddEdge(T x, T y)
    {
        l[x].push_back(y);
    }

    // Ordering is passed by reference as we want to maintain a single list
    void dfs_helper(T source, map<T, bool> &Visited, list<T> &ordering) // Value is passed by reference as we do not want to make a copy and it remains same everywhere
    {
        // Recursive function that will traverse the graph
        //cout << source << " ";
        Visited[source] = true;

        // Go to all the neighbours of the node that is not visited one by one
        for (T nbr : l[source])
        {
            if (!Visited[nbr])
            {
                dfs_helper(nbr, Visited, ordering);
            }
        }
        // At this point
        ordering.push_front(source);
        return;
    }

    void dfs(T source)
    {
        map<T, bool> Visited;
        list<T> ordering;
        // In the beginning, mark all the nodes as unvisited
        for (auto p : l)
        {
            T node = p.first;
            Visited[node] = false;
        }

        for (auto p : l)
        {
            T node = p.first;
            if (!Visited[node])
                dfs_helper(source, Visited, ordering);
        }

        // Finally print the list
        for (auto node : ordering)
        {
            cout << node << endl;
        }
    }
};

int main()
{
    Graph<string> g;

    g.AddEdge("Python", "DataPreprocessing");
    g.AddEdge("Python", "Pytorch");
    g.AddEdge("Python", "ML");
    g.AddEdge("DataPreprocessing", "ML");
    g.AddEdge("Pytorch", "DL");
    g.AddEdge("ML", "DL");
    g.AddEdge("DL", "FaceRecognition");
    g.AddEdge("Dataset", "FaceRecognition");

    g.dfs("Python");
    return 0;
}