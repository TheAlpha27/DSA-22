#include <bits/stdc++.h>
using namespace std;

#define loop(i, a, b) for (int i = a; i < b; i++)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define init(a) \
    int a;      \
    cin >> a;
#define vi vector<int>
#define pi pair<int, int>
#define que queue<int>
#define sta stack<int>
#define ll long long
#define lb cout << endl
#define mod 1000000007
#define cin(a)        \
    int i;            \
    for (auto &i : a) \
    cin >> i
#define cout(a)       \
    int j;            \
    for (auto &j : a) \
    cout << j

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    init(n);
    vi a(n);
    cin(a);

    vector<int> adj[n];
    vector<bool> vis(n, 0);
    for (int i = 1; i < n; i++)
    {
        adj[i].push_back(a[i]);
        adj[a[i]].push_back(i);
    }

    queue<vector<int>> q;
    q.push({0, 1, 0});
    vis[0] = 1;

    int ans = 1;
    while (!q.empty())
    {
        vector<int> curr = q.front();
        q.pop();
        // cout << curr[i] << " ";
        ans = max(ans, curr[1]);

        for (auto nbr : adj[curr[0]])
        {
            if (!vis[nbr])
            {
                if (nbr % 2 == 1)
                {
                    if (curr[2] == 0)
                    {
                        vis[nbr] = true;
                        q.push({nbr, curr[1] + 1, 1});
                    }
                }
                else
                {
                    q.push({nbr, curr[1] + 1, curr[2]});
                    vis[nbr] = true;
                }
            }
        }
    }

    cout << ans;

    return 0;
}