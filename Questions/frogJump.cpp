// Normal Recursion method
int solve(int n, vector<int> &heights)
{
    if (n == 0)
    {
        return 0;
    }
    int left = solve(n - 1, heights) + abs(heights[n] - heights[n - 1]);
    int right = 1e9;
    if (n > 1)
    {
        right = solve(n - 2, heights) + abs(heights[n] - heights[n - 2]);
    }
    return min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    return solve(n - 1, heights);
}

// Top_Down Approach
#include <bits/stdc++.h>
int solve(int n, vector<int> &heights, vector<int> &dp)
{
    if (n == 0)
    {
        dp[0] = 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int left = solve(n - 1, heights, dp) + abs(heights[n] - heights[n - 1]);
    int right = 1e9;
    if (n > 1)
    {
        right = solve(n - 2, heights, dp) + abs(heights[n] - heights[n - 2]);
    }
    return dp[n] = min(left, right);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    solve(n, heights, dp);
    return dp[n - 1];
}

// Bottom_Up Approach
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = 1e9;
        if (i > 1)
        {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        dp[i] = min(left, right);
    }
    return dp[n - 1];
}

// Space optimised Approach
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    //     vector<int> dp(n+1, -1);
    int prev1 = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++)
    {
        int left = prev1 + abs(heights[i] - heights[i - 1]);
        int right = 1e9;
        if (i > 1)
        {
            right = prev2 + abs(heights[i] - heights[i - 2]);
        }
        int curr = min(left, right);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}