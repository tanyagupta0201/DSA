#include <iostream>
#include <cstring>
#include <map>
#include <list>
using namespace std;

class Graph
{
    // Adjacency List
    map<string, list<pair<string, int>>> l;

public:
    void AddEdge(string x, string y, bool bidirec, int wt)
    {
        l[x].push_back(make_pair(y, wt));
        if (bidirec)
        {
            l[y].push_back(make_pair(x, wt));
        }
    }

    void PrintAdjList()
    {
        // Iterate over all the keys in the map
        for (auto p : l)
        {
            string source = p.first;
            list<pair<string, int>> nbrs = p.second;

            cout << source << " -> ";
            for (auto nbr : nbrs)
            {
                string destination = nbr.first;
                int distance = nbr.second;

                cout << destination << " " << distance << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;
    g.AddEdge("A", "B", true, 20);
    g.AddEdge("B", "D", true, 40);
    g.AddEdge("A", "C", true, 10);
    g.AddEdge("C", "D", true, 90);
    g.AddEdge("A", "D", false, 20);

    g.PrintAdjList();
    return 0;
}