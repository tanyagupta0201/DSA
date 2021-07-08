/*  
    Bipartite Graph (Two Colouring Problem)
    -> You can divide all vertices of graph in 2 sets such that all edges of the graph are from set 1 to set2 

*/

#include <bits/stdc++.h>
using namespace std;

bool dfs_helper(vector<int> graph[], int node, int *visited, int parent, int color)
{
    // Come to node
    visited[node] = color; // Color is either 1 or 2 which means it is visited

    for (auto nbr : graph[node])
    {
        if (visited[nbr] == 0)
        {
            int sub_problem = dfs_helper(graph, nbr, visited, node, 3 - color);
            if (sub_problem == false)
            {
                return false;
            }
        }
        else if (nbr != parent and color == visited[nbr])
        {
            return false;
        }
    }
    return true;
}

bool dfs(vector<int> graph[], int n)
{
    int visited[n] = {0}; // 0 - not visited, 1 - visited (Color is 1 or 2)

    int color = 1;
    int ans = dfs_helper(graph, 0, visited, -1, color);

    // Colors
    for (int i = 0; i < n; i++)
    {
        cout << i << " - Color " << visited[i] << endl;
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n];

    while (m--)
    {
        int x, y;
        cin >> x >> y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // BFS or DFS, by coloring the nodes at each step (current node has color 1)
    if (dfs(graph, n))
    {
        cout << "Yes, it is a Bipartite Graph !!" << endl;
    }
    else
    {
        cout << "No, it is not a Bipartite Graph !!" << endl;
    }

    return 0;
}

/*

OUTPUT:

INPUT 1:

5 4
0 1 
0 2
1 3
2 4

OUTPUT 1:

0 - Color 1
1 - Color 2
2 - Color 2
3 - Color 1
4 - Color 1
Yes, it is a Bipartite Graph !!


INPUT 2:

5 6
0 1
0 2
1 3
2 4
3 2
3 4

OUTPUT 2:

0 - Color 1
1 - Color 2
2 - Color 2
3 - Color 1
4 - Color 1
No, it is not a Bipartite Graph !!

*/