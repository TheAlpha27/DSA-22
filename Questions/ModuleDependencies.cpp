// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail

#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<vector<int>> &adj)
{
    vector<int> indegree(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            indegree[j]++;
        }
    }
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto i : adj[front])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
    }
    return ans;
}
int main()
{

    /*
    //Sample code to perform I/O
    int num;
    cin >> num;				// Reading input from STDIN
    cout <<num << endl;		// Writing output to STDOUT
    */

    // Write your code here
    int N;
    cin >> N;
    int I;
    cin >> I;
    vector<vector<int>> edges(N, vector<int>(N+1, 0));
    while (I > 0)
    {
        int a, b;
        cin >> a;
        cin >> b;
        edges[a].push_back(b);
        I--;
    }
    vector<int> ans(N + 1);
    ans = topoSort(N, edges);
    for (auto i : ans)
    {
        if (i != 0)
        {
            cout << ans[i] << " ";
        }
    }
}