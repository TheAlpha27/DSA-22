#include <bits/stdc++.h>
void DFS(int node, vector<int> &disc, vector<int> &low, int parent, vector<bool> &visited, vector<vector<int>> &res, unordered_map<int, list<int>> &adj, int &timer)
{
    visited[node] = true;
    disc[node] = timer;
    low[node] = timer;
    timer++;
    for (auto nbr : adj[node])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!visited[nbr])
        {
            DFS(nbr, disc, low, node, visited, res, adj, timer);
            low[node] = min(low[node], low[nbr]);
            if (low[nbr] > disc[node])
            {
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                res.push_back(ans);
            }
        }
        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e)
{
    // Write your code here
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    vector<bool> visited(v, false);
    vector<vector<int>> res;
    int parent = -1;
    int timer = 0;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            DFS(i, disc, low, parent, visited, res, adj, timer);
        }
    }
    return res;
}