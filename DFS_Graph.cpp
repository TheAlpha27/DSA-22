void DFS(int node, vector<int> adj[], unordered_map<int, bool> &visited, vector<int> &ans)
{
    ans.push_back(node);
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            DFS(i, adj, visited, ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> ans;
    unordered_map<int, bool> visited;
    DFS(0, adj, visited, ans);
    return ans;
}