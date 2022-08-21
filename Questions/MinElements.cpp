// Recursion
int solve(int ind, int tar, vector<int> &num)
{
    if (tar == 0)
    {
        return 0;
    }
    if (ind == 0)
    {
        if (tar % num[0] == 0)
        {
            return tar / num[0];
        }
        else
        {
            return 1e9;
        }
    }
    int notPick = 0 + solve(ind - 1, tar, num);
    int pick = INT_MAX;
    if (tar >= num[ind])
    {
        pick = 1 + solve(ind, tar - num[ind], num);
    }
    return min(pick, notPick);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int size = num.size();
    int ans = solve(size - 1, x, num);
    if (ans >= 1e9)
    {
        return -1;
    }
    return ans;
}

// Top down Approach
int solve(int ind, int tar, vector<int> &num, vector<vector<int>> &dp)
{
    if (tar == 0)
    {
        return 0;
    }
    if (ind == 0)
    {
        if (tar % num[0] == 0)
        {
            return tar / num[0];
        }
        else
        {
            return 1e9;
        }
    }
    if (dp[ind][tar] != -1)
    {
        return dp[ind][tar];
    }
    int notPick = 0 + solve(ind - 1, tar, num, dp);
    int pick = INT_MAX;
    if (tar >= num[ind])
    {
        pick = 1 + solve(ind, tar - num[ind], num, dp);
    }
    return dp[ind][tar] = min(pick, notPick);
}

// Bottom Up Approach
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int size = num.size();
    vector<vector<int>> dp(size, vector<int>(x + 1, 0));
    for (int tar = 0; tar <= x; tar++)
    {
        if (tar % num[0] == 0)
        {
            dp[0][tar] = tar / num[0];
        }
        else
        {
            dp[0][tar] = 1e9;
        }
    }
    for (int ind = 1; ind < size; ind++)
    {
        for (int tar = 1; tar <= x; tar++)
        {
            int notPick = 0 + dp[ind - 1][tar];
            int pick = 1e9;
            if (tar >= num[ind])
            {
                pick = 1 + dp[ind][tar - num[ind]];
            }
            dp[ind][tar] = min(pick, notPick);
        }
    }
    if (dp[size - 1][x] >= 1e9)
    {
        return -1;
    }
    return dp[size - 1][x];
}

// Space Optimized
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int size = num.size();
    vector<int> prev(x + 1, 0);
    for (int tar = 0; tar <= x; tar++)
    {
        if (tar % num[0] == 0)
        {
            prev[tar] = tar / num[0];
        }
        else
        {
            prev[tar] = 1e9;
        }
    }
    for (int ind = 1; ind < size; ind++)
    {
        vector<int> curr(x + 1, 0);
        for (int tar = 1; tar <= x; tar++)
        {
            int notPick = 0 + prev[tar];
            int pick = 1e9;
            if (tar >= num[ind])
            {
                pick = 1 + curr[tar - num[ind]];
            }
            curr[tar] = min(pick, notPick);
        }
        prev = curr;
    }
    if (prev[x] >= 1e9)
    {
        return -1;
    }
    return prev[x];
}