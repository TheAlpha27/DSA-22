// Top Down Approach
#include <bits/stdc++.h>
int solve(int ind, int tar, vector<int> &num, vector<vector<int>> &dp)
{
    if (tar < 0)
    {
        return 0;
    }
    if (ind < 0)
    {
        return tar == 0;
    }
    if (dp[ind][tar] != -1)
    {
        return dp[ind][tar];
    }
    int notPick = solve(ind - 1, tar, num, dp);
    int pick = 0;
    if (tar >= num[ind])
    {
        pick = solve(ind - 1, tar - num[ind], num, dp);
    }
    return dp[ind][tar] = pick + notPick;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return solve(n - 1, tar, num, dp);
}