// Dijkstra's algorithm implementation with Restore
#include <bits/stdc++.h>
using namespace std; 

#define INF 1e9

// Undirected weighted graph class
class Graph 
{
    vector<vector<pair<int, int>>> g;

public: 

    Graph(int nodes)
    {
        g.resize(nodes + 1);
    }

    void addEdge(int to, int from, int weight)
    {
        g[to].push_back({from, weight});
        g[from].push_back({to, weight});
    }

    vector<int> dijkstraPQ(int nodes, int source, vector<int> &pred)
    {
        // Initializing the predecessor vector
        pred.assign(nodes, -1);

        vector<int> dist(nodes, INF);  // For storing distnace from source
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initializing source node distance, and pushing the source into the priority queue
        dist[source] = 0;
        pq.push({0, source});

        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();

            // Looping in for all the adjacent nodes of u
            for(auto &next: g[u])
            {
                int v = next.first;
                int w = next.second;

                if(dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    pred[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }

    vector<int> restorePath(int source, int terminal, vector<int> &pred)
    {
        vector<int> path;

        for(int v = terminal; v != source; v = pred[v])
            path.push_back(v);
        
        reverse(path.begin(), path.end());

        return path;
    }
};

int main()
{
    int nodes, edges, source, terminal;
    int u, v, w;

    cout << "Enter nodes and edges: ";
    cin >> nodes >> edges;

    Graph graph(nodes + 1);

    cout << "Enter edges with weights: \n";
    for (int i = 0; i < edges; i++)
    {
        cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    cout << "Enter source: ";
    cin >> source;

    vector<int> pred;
    vector<int> dist = graph.dijkstraPQ(nodes, source, pred);

    cout << "The distances are: ";
    for (int i = 0; i < nodes; i++)
        cout << dist[i] << " ";
    cout << "\n";

    cout << "The predecessors are: ";
    for(auto ele: pred)
        cout << ele << " ";
    cout << "\n";

    cout << "Enter Terminal: ";
    cin >> terminal;
    vector<int> path = graph.restorePath(source, terminal, pred);

    cout << "The path is: ";
    for(auto ele: path)
        cout << ele << " ";
    cout << "\n";

    return 0;
}