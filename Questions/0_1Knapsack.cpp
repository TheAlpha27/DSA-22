// Top Down Approach
int solve(int ind, int w, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp)
{
    if (w == 0)
    {
        return 0;
    }
    if (ind == 0)
    {
        if (w >= weight[0])
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }
    if (dp[ind][w] != -1)
    {
        return dp[ind][w];
    }
    int notPick = solve(ind - 1, w, weight, value, dp);
    int pick = -1e8;
    if (w >= weight[ind])
    {
        pick = value[ind] + solve(ind - 1, w - weight[ind], weight, value, dp);
    }
    return dp[ind][w] = max(pick, notPick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    return solve(n - 1, maxWeight, weight, value, dp);
}

// Bottom Up Approach
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    for (int w = 0; w <= maxWeight; w++)
    {
        if (w >= weight[0])
        {
            dp[0][w] = value[0];
        }
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 1; w <= maxWeight; w++)
        {
            int notPick = dp[ind - 1][w];
            int pick = -1e8;
            if (w >= weight[ind])
            {
                pick = value[ind] + dp[ind - 1][w - weight[ind]];
            }
            dp[ind][w] = max(pick, notPick);
        }
    }
    return dp[n - 1][maxWeight];
}

// Space Optimized
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<int> prev(maxWeight + 1, 0);
    for (int w = 0; w <= maxWeight; w++)
    {
        if (w >= weight[0])
        {
            prev[w] = value[0];
        }
    }
    for (int ind = 1; ind < n; ind++)
    {
        vector<int> curr(maxWeight + 1, 0);
        for (int w = 1; w <= maxWeight; w++)
        {
            int notPick = prev[w];
            int pick = -1e8;
            if (w >= weight[ind])
            {
                pick = value[ind] + prev[w - weight[ind]];
            }
            curr[w] = max(pick, notPick);
        }
        prev = curr;
    }
    return prev[maxWeight];
}