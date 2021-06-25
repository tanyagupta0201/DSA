#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int V;
    // Array of List
    list<int> *l; // Since the size of V is not known yet, we are making pointer

public:
    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    }

    void AddEdge(int x, int y)
    {
        // Adding edge between two nodes(which are integers)
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void PrintAdjList()
    {
        // Iterate over all the vertices
        for (int i = 0; i < V; i++)
        {
            cout << "Vertex " << i << " -> ";
            for (int neighbour : l[i])
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g(4);

    /*
            0 -- 1
             \  /
              2
              |
              3

    */

    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(2, 3);
    g.AddEdge(1, 2);

    g.PrintAdjList();

    return 0;
}