#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class DirectedGraph
{
private:
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    // DFS helper
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
    DirectedGraph(int vertices)
    {
        V = vertices;
        adj.resize(V);
    }

    // Add directed edge (u -> v)
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
    }

    // Remove directed edge (u -> v)
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

        // Remove all edges pointing to v
        for (int i = 0; i < V; i++)
        {
            for (auto it = adj[i].begin(); it != adj[i].end();)
            {
                if (*it == v)
                    it = adj[i].erase(it);
                else
                {
                    if (*it > v)
                        (*it)--; // adjust index
                    it++;
                }
            }
        }

        // Remove adjacency list of v
        adj.erase(adj.begin() + v);
        V--;
    }

    // Display graph
    void display()
    {
        cout << "\nDirected Graph Adjacency List:\n";
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (int x : adj[i])
                cout << x << " ";
            cout << endl;
        }
    }

    // Count Isolated Nodes (in-degree = 0 AND out-degree = 0)
    int countIsolatedNodes()
    {
        vector<int> indegree(V, 0);

        // Count in-degree
        for (int u = 0; u < V; u++)
        {
            for (int v : adj[u])
                indegree[v]++;
        }

        int count = 0;
        for (int i = 0; i < V; i++)
        {
            if (adj[i].empty() && indegree[i] == 0)
                count++;
        }
        return count;
    }

    // Count Self Loops (u -> u)
    int countSelfLoops()
    {
        int count = 0;
        for (int i = 0; i < V; i++)
        {
            for (int v : adj[i])
            {
                if (v == i)
                    count++;
            }
        }
        return count;
    }

    // Check if Directed Graph is Complete (u -> v exists for all u!=v)
    bool isCompleteGraph()
    {
        for (int i = 0; i < V; i++)
        {
            if ((int)adj[i].size() != V - 1)
                return false;
        }
        return true;
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

    // Create directed graph with 5 vertices
    DirectedGraph g(5);

    // Add directed edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 4);

    // Display graph
    g.display();

    // BFS and DFS
    g.BFS(0);
    g.DFS(0);

    // Remove a directed edge
    g.removeEdge(1, 3);
    cout << "\nAfter removing edge (1 -> 3):";
    g.display();

    // Add a new vertex
    g.addVertex();
    cout << "\nAfter adding a vertex:";
    g.display();

    // Remove a vertex
    g.removeVertex(2);
    cout << "\nAfter removing vertex 2:";
    g.display();

    return 0;
}
