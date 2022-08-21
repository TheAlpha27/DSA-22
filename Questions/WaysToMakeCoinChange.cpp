long solve(int ind, int tar, int *arr)
{
    if (tar == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        if (tar % arr[ind] == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    long notPick = solve(ind - 1, tar, arr);
    long pick = 0;
    if (tar >= arr[ind])
    {
        pick = solve(ind, tar - arr[ind], arr);
    }
    return pick + notPick;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    long ans = solve(n - 1, value, denominations);
    return ans;
}

// Top Down
#include <bits/stdc++.h>
long solve(int ind, int tar, int *arr, vector<vector<long>> &dp)
{
    if (tar == 0)
    {
        return 1;
    }
    if (ind == 0)
    {
        if (tar % arr[ind] == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[ind][tar] != -1)
    {
        return dp[ind][tar];
    }
    long notPick = solve(ind - 1, tar, arr, dp);
    long pick = 0;
    if (tar >= arr[ind])
    {
        pick = solve(ind, tar - arr[ind], arr, dp);
    }
    return dp[ind][tar] = pick + notPick;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    long ans = solve(n - 1, value, denominations, dp);
    return ans;
}