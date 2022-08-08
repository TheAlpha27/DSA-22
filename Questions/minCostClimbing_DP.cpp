#include <bits/stdc++.h>
using namespace std;
int solve_topDown(vector<int> cost, int n, vector<int> &dp)
{
    if(n == 0)
    {
        return cost[0];
    }
    if(n == 1)
    {
        return cost[1];
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = cost[n] + min(solve_topDown(cost, n-1, dp), solve_topDown(cost, n-2, dp));
    return dp[n];
}
int solve_bottomUp(vector<int> cost, int n)
{
    vector<int> dp(n+1);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i-1], dp[i-2]); 
    }
    return min(dp[n-1], dp[n-2]);
}

int solve_SpaceOpt(vector<int> cost, int N)
{
    int prev1 = cost[1];
        int prev2 = cost[0];
        int curr;
        for(int i = 2; i < N; i++)
        {
            curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
}
int main()
{
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    int n = cost.size();
    vector<int> dp(n+1, -1);
    cout<<"minimum cost: "<<min(solve_topDown(cost, n-1, dp), solve_topDown(cost, n-2, dp))<<endl;
    cout<<"minimum cost: "<<solve_bottomUp(cost, n)<<endl;
    cout<<"minimum cost: "<<solve_SpaceOpt(cost, n)<<endl;
    return 0;
}