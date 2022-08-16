bool solve(int n, int k, vector<int> &arr)
{
    if (k == 0)
    {
        return true;
    }
    if (n == 0)
    {
        if (arr[0] == k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool notPick = solve(n - 1, k, arr);
    bool pick = false;
    if (k >= arr[n])
    {
        pick = solve(n - 1, k - arr[n], arr);
    }
    if (pick || notPick)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    return solve(n, k, arr);
}

// Top_Down
bool solve(int n, int k, vector<int> &arr, vector<vector<int>> &dp)
{
    if (dp[n][k] != -1)
    {
        return dp[n][k];
    }
    if (k == 0)
    {
        return true;
    }
    if (n == 0)
    {
        if (arr[0] == k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    bool notPick = solve(n - 1, k, arr, dp);
    bool pick = false;
    if (k >= arr[n])
    {
        pick = solve(n - 1, k - arr[n], arr, dp);
    }
    return dp[n][k] = (pick || notPick);
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    return solve(n, k, arr, dp);
}

// Bottom_UP Approach
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notPick = dp[i - 1][target];
            bool pick = false;
            if (target >= arr[i])
            {
                pick = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = (pick || notPick);
        }
    }
    return dp[n - 1][k];
}

// Space Optimised
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = true;
    curr[0] = true;
    prev[arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool notPick = prev[target];
            bool pick = false;
            if (target >= arr[i])
            {
                pick = prev[target - arr[i]];
            }
            curr[target] = (pick || notPick);
        }
        prev = curr;
    }
    return prev[k];
}