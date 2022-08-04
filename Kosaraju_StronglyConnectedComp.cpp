#include<bits/stdc++.h>
void DFS(int node, vector<bool> &visited, stack<int> &ts, unordered_map<int, list<int>> &revAdj)
{
    visited[node] = true;
    for(auto i : revAdj[node])
    {
        if(!visited[i])
        {
            DFS(i, visited, ts, revAdj);
        }
    }
}

void topoSort(int node, vector<bool> &visited, stack<int> &ts, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for(auto i : adj[node])
    {
        if(!visited[i])
        {
            topoSort(i, visited, ts, adj);
        }
    }
    ts.push(node);
    return;
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
    unordered_map<int, list<int>> adj;
    for(int i = 0; i < edges.size(); i ++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool> visited(v, false);
    stack <int> ts;
    for(int i = 0; i < v; i++)
    {
        if(!visited[i])
        {
            topoSort(i, visited, ts, adj);
        }
    }
    for(int i = 0; i < v; i ++)
    {
        visited[i] = false;
    }
    unordered_map<int, list<int>> revAdj;
    for(int i = 0; i < edges.size(); i ++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        revAdj[v].push_back(u);
    }
    int count = 0;
    while(!ts.empty())
    {
        int top = ts.top();
        ts.pop();
        if(!visited[top])
        {
            count++;
            DFS(top, visited, ts, revAdj);
        }
    }
    return count;
}