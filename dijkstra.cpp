#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i = 0; i <edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> dist(vertices, INT_MAX);
    dist[source] = 0;
    set <pair<int,int>> st; //node, dist
    st.insert(make_pair(source,0));
    while(!st.empty())
    {
        auto top = *(st.begin());
        int node = top.first;
        int distance = top.second;
        st.erase(top);
        for(auto i: adj[node])
        {
            int n = i.first;
            int d = i.second;
            if(dist[n] > distance + d)
            {
                auto record = (st.find(make_pair(n, dist[n])));
                if(record != st.end())
                {
                    st.erase(record);
                }
                dist[n] = d + distance;
                st.insert(make_pair(n, dist[n]));
            }
        }
    }
    return dist;
}
