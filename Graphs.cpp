#include <bits/stdc++.h>
using namespace std;
class Graph
{
public:
    map<int, set<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 => undirected
        // direction = 1 => directed

        // create an edge from u to v
        adj[u].insert(v);
        // check for directed or undirected
        if (!direction)
        { // creating edge from v to u
            adj[v].insert(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << "->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};

void BFS(int node, map<int, set<int>> &adj, unordered_map<int, bool> &visited, vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{
    int n, e;
    cout << "Enter the number of nodes" << endl;
    cin >> n;
    cout << "Enter the number of edges" << endl;
    cin >> e;
    Graph g;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 0); // creating undirected graph as of now
    }
    g.printAdjList();
    vector<int> ans;
    unordered_map<int, bool> visited;
    for (auto i : g.adj)
    {
        if (!visited[i.first])
        {
            BFS(i.first, g.adj, visited, ans);
        }
    }
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}