#include <bits/stdc++.h>
void BFS(unordered_map<int, list<int>> adj, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, int node)
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
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }
}

vector<int> findAns(int s, int t, unordered_map<int, int> parent)
{
    vector<int> ans;
    ans.push_back(t);
    while (t != s)
    {
        t = parent[t];
        ans.push_back(t);
    }
    return ans;
}

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    BFS(adj, visited, parent, 1);
    vector<int> ans = findAns(s, t, parent);
    int size = ans.size();
    reverse(ans.begin(), ans.end());
    return ans;
}