int solve(int ind, int w, vector<int> &profit, vector<int> &weight)
{
    if (w == 0)
    {
        return 0;
    }
    if (ind < 0)
    {
        return 0;
    }
    if (ind == 0)
    {
        int sum = 0;
        while (w >= weight[0])
        {
            sum = sum + profit[0];
            w = w - weight[0];
        }
        return sum;
    }
    int notPick = solve(ind - 1, w, profit, weight);
    int pick = -1e9;
    if (w >= weight[ind])
    {
        pick = profit[ind] + solve(ind, w - weight[ind], profit, weight);
    }
    return max(pick, notPick);
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    return solve(n - 1, w, profit, weight);
}

// Top Down Approach
int solve(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp)
{
    if (w == 0)
    {
        return 0;
    }
    if (ind < 0)
    {
        return 0;
    }
    if (ind == 0)
    {
        int sum = 0;
        while (w >= weight[0])
        {
            sum = sum + profit[0];
            w = w - weight[0];
        }
        return sum;
    }
    if (dp[ind][w] != -1)
    {
        return dp[ind][w];
    }
    int notPick = solve(ind - 1, w, profit, weight, dp);
    int pick = -1e9;
    if (w >= weight[ind])
    {
        pick = profit[ind] + solve(ind, w - weight[ind], profit, weight, dp);
    }
    return dp[ind][w] = max(pick, notPick);
}