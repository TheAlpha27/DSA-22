bool solve(vector<int> &arr, int ind, int target)
{
    if (target == 0)
    {
        return true;
    }
    if (ind == 0)
    {
        if (arr[ind] == target)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
    bool notPick = solve(arr, ind - 1, target);
    bool pick = false;
    if (target >= arr[ind])
    {
        pick = solve(arr, ind - 1, target - arr[ind]);
    }
    return pick || notPick;
}
bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int sum = 0;
    for (auto i : arr)
    {
        sum = sum + i;
    }
    if (sum % 2 == 0)
        return solve(arr, n - 1, sum / 2);
    else
    {
        return false;
    }
}

// Top_Down Approach
bool solve(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }
    if (ind == 0)
    {
        if (arr[ind] == target)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }
    bool notPick = solve(arr, ind - 1, target, dp);
    bool pick = false;
    if (target >= arr[ind])
    {
        pick = solve(arr, ind - 1, target - arr[ind], dp);
    }
    return dp[ind][target] = pick || notPick;
}

// Bottom Up Approach
bool solve(vector<int> &arr, int ind, int target)
{
    vector<vector<int>> dp(ind + 1, vector<int>(target + 1, 0));
    for (int i = 0; i <= ind; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int i = 1; i <= ind; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            bool notPick = dp[i - 1][j];
            bool pick = false;
            if (j >= arr[i])
            {
                pick = dp[i - 1][j - arr[i]];
            }
            dp[i][j] = pick || notPick;
        }
    }
    return dp[ind][target];
}

// Space Optimised
bool solve(vector<int> &arr, int ind, int target)
{
    vector<bool> prev(target + 1, 0);
    for (int i = 0; i <= ind; i++)
    {
        prev[0] = true;
    }
    prev[arr[0]] = true;
    for (int i = 1; i <= ind; i++)
    {
        vector<bool> curr(target + 1, 0);
        for (int j = 1; j <= target; j++)
        {
            bool notPick = prev[j];
            bool pick = false;
            if (j >= arr[i])
            {
                pick = prev[j - arr[i]];
            }
            curr[j] = pick || notPick;
        }
        prev = curr;
    }
    return prev[target];
}