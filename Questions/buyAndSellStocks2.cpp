// Top Down Approach
#include <bits/stdc++.h>
long solve(int ind, bool flag, long *values, int n, vector<vector<long>> &dp)
{
    if (ind == n)
    {
        return 0;
    }
    if (dp[ind][flag] != -1)
    {
        return dp[ind][flag];
    }
    long profit = 0;
    if (flag)
    {
        profit = max(-values[ind] + solve(ind + 1, 0, values, n, dp), 0 + solve(ind + 1, 1, values, n, dp));
    }
    else
    {
        profit = max(values[ind] + solve(ind + 1, 1, values, n, dp), 0 + solve(ind + 1, 0, values, n, dp));
    }
    return dp[ind][flag] = profit;
}
long getMaximumProfit(long *values, int n)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return solve(0, 1, values, n, dp);
}

// Bottom Up Approach
long getMaximumProfit(long *values, int n)
{
    // Write your code here
    vector<vector<long>> dp(n + 1, vector<long>(2, 0));
    dp[n][0] = 0;
    dp[n][1] = 0;
    long profit = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int flag = 0; flag <= 1; flag++)
        {
            if (flag)
            {
                profit = max(-values[ind] + dp[ind + 1][0], 0 + dp[ind + 1][1]);
            }
            else
            {
                profit = max(values[ind] + dp[ind + 1][1], 0 + dp[ind + 1][0]);
            }
            dp[ind][flag] = profit;
        }
    }
    return dp[0][1];
}

// Space Optimized
long getMaximumProfit(long *values, int n)
{
    // Write your code here
    vector<long> next(2, 0);
    next[0] = 0;
    next[1] = 0;
    long profit = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        vector<long> curr(2, 0);
        for (int flag = 0; flag <= 1; flag++)
        {
            if (flag)
            {
                profit = max(-values[ind] + next[0], 0 + next[1]);
            }
            else
            {
                profit = max(values[ind] + next[1], 0 + next[0]);
            }
            curr[flag] = profit;
        }
        next = curr;
    }
    return next[1];
}