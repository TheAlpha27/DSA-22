bool DFS(int node, vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, bool> DFSvisited)
{
    DFSvisited[node] = true;
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            if (DFS(i, adj, visited, DFSvisited))
            {
                return true;
            }
        }
        else if (visited[i] && DFSvisited[i])
        {
            return true;
        }
    }
    DFSvisited[node] = false;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSvisited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (DFS(i, adj, visited, DFSvisited))
            {
                return true;
            }
        }
    }
    return false;
}

// Use vector instead of unordered_map to avoid TLE