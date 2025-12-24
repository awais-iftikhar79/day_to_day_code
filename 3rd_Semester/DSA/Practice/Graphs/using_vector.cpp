#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    // Helper function for DFS
    void DFS_Helper(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";

        for (int neighbor : adj[v])
        {
            if (!visited[neighbor])
            {
                DFS_Helper(neighbor, visited);
            }
        }
    }

public:
    // Constructor
    Graph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    // Add edge (undirected)
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Remove edge (undirected)
    void removeEdge(int u, int v)
    {
        for (auto it = adj[u].begin(); it != adj[u].end(); it++)
        {
            if (*it == v)
            {
                adj[u].erase(it);
                break;
            }
        }

        for (auto it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (*it == u)
            {
                adj[v].erase(it);
                break;
            }
        }
    }

    // Add a new vertex
    void addVertex()
    {
        adj.push_back(vector<int>());
        V++;
    }

    // Remove a vertex
    void removeVertex(int v)
    {
        // Remove v from all adjacency lists
        for (int i = 0; i < V; i++)
        {
            for (auto it = adj[i].begin(); it != adj[i].end();)
            {
                if (*it == v)
                    it = adj[i].erase(it);
                else
                {
                    if (*it > v)
                        (*it)--; // Adjust indices
                    it++;
                }
            }
        }

        // Remove the adjacency list of v
        adj.erase(adj.begin() + v);
        V--;
    }

    // Display the graph
    void display()
    {
        cout << "\nGraph Adjacency List:\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (int x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }

    // Breadth First Search
    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "\nBFS Traversal: ";

        while (!q.empty())
        {
            int curr = q.front();
            q.pop();

            cout << curr << " ";

            for (int neighbor : adj[curr])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        cout << endl;
    }

    // Depth First Search
    void DFS(int start)
    {
        vector<bool> visited(V, false);
        cout << "\nDFS Traversal: ";
        DFS_Helper(start, visited);
        cout << endl;
    }
};

int main()
{

    // Create graph with 4 vertices
    Graph g(4);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    // Display graph
    g.display();

    // BFS and DFS
    g.BFS(0);
    g.DFS(0);

    // Remove an edge
    g.removeEdge(0, 2);
    cout << "\nAfter removing edge (0,2):";
    g.display();

    // Add a new vertex
    g.addVertex();
    cout << "\nAfter adding a vertex:";
    g.display();

    // Remove a vertex
    g.removeVertex(1);
    cout << "\nAfter removing vertex 1:";
    g.display();

    return 0;
}
