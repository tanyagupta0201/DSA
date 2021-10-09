/*  0 - 1 BFS 
    Given a graph where every edge has weight as either 0 or 1.
    A source vertex is also given in the graph. 
    Find the shortest path from source vertex to every other vertex. 
*/

#include <bits/stdc++.h>
using namespace std;

void fillAdjList(vector<pair<int, int>> adjList[], int nodes, int edges)
{
    int x, y, w;
    for(int i = 0; i < edges; i++)
    {
        cin >> x >> y >> w;
        adjList[x].push_back({y, w}); // Inserting y in adjacency list of x with weight
        adjList[y].push_back({x, w}); // Inserting x in adjacency list of y with weight(Undirected)

    }
}

void printAdjList(vector<pair<int, int>> adjList[], int nodes)
{
    for(int i = 0; i < nodes; i++)
    {
        cout << "Adjacency List of vertex " << i << ": HEAD";
        
        for(auto ele: adjList[i])
            cout << "-> " << ele.first << "(" << ele.second << ")";
        
        cout << "\n";
    }
}

void zeroOneBFS(vector<pair<int, int>> adjList[], int nodes, int src)
{
    vector<int> dist(nodes, INT_MAX);

    deque<int> q;
    
    dist[src] = 0;
    q.push_back(src);
    
    while(!q.empty())
    {
        int v = q.front();
        q.pop_front();

        for(int i = 0; i < adjList[v].size(); i++)
        {
            if(dist[adjList[v][i].first] > dist[v] + adjList[v][i].second)
            {
                dist[adjList[v][i].first] = dist[v] + adjList[v][i].second;

                if(adjList[v][i].second == 0)
                    q.push_front(adjList[v][i].first);
                else 
                    q.push_back(adjList[v][i].first);
            }
        }
    }
    
    for(int i = 0; i < nodes; i++)
        cout << dist[i] << " ";
    cout << "\n";
}

int main()
{
    int x, y, w, nodes, edges, src;
    cout << "Enter number of Nodes and Edges: ";
    cin >> nodes >> edges;

    vector<pair<int, int>> adjList[nodes];

    cout << "Enter Edges (source destination weight): \n";
    cout << "Note: The weight must be either 0 or 1.\n";
    
    fillAdjList(adjList, nodes, edges);

    cout << "\n";
    printAdjList(adjList, nodes);

    cout << "\nEnter source: ";
    cin >> src;

    zeroOneBFS(adjList, nodes, src);

    return 0;
}