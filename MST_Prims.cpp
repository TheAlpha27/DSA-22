#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i = 0; i < g.size(); i ++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> parent(n+1, -1);
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    key[1] = 0;
    mst[0] = true;
    for(int i = 1; i <= n; i++)
    {
        int u;
        int min = INT_MAX;
        for(int i = 1; i<= n; i++)
        {
            if(key[i] < min && mst[i] == false)
            {
                min = key[i];
                u = i;
            }
        }
        mst[u] = true;
        for(auto i : adj[u])
        {
            int node = i.first;
            int dist = i.second;
            if( mst[node] == false && dist < key[node])
            {
                parent[node] = u;
                key[node] = dist;
            }
        }  
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i = 2; i <= n; i++)
    {
        ans.push_back(make_pair(make_pair(parent[i] , i), key[i]));
    }
    return ans;
}
