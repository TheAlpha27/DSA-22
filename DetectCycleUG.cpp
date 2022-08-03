// Using BFS
void BFS(int node, vector<int> adj[], unordered_map<int, bool> &visited, unordered_map<int, int> parent, bool &ans)
{
    queue<int> q;
    q.push(node);
    visited[node] = true;
    parent[node] = -1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (auto i : adj[front])
        {
            if (!visited[i])
            {
                visited[i] = true;
                parent[i] = front;
                q.push(i);
            }
            else if (visited[i] == true && parent[front] != i)
            {
                ans = true;
                break;
            }
        }
        if (ans == true)
        {
            return;
        }
    }
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    BFS(0, adj, visited, parent, ans);
    return ans;
}

// Using DFS
bool DFS(int node, int parent, vector<int> adj[], unordered_map<int, bool> &visited)
{
    visited[node] = true;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            if (DFS(i, node, adj, visited))
            {
                return true;
            }
        }
        else if (i != parent)
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    unordered_map<int, bool> visited;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (DFS(i, -1, adj, visited))
            {
                return true;
            }
        }
    }
    return false;
}