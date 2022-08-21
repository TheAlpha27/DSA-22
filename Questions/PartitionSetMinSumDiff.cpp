int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write your code here.
    int s = 0;
    for (auto i : arr)
    {
        s = s + i;
    }
    vector<vector<bool>> dp(n, vector<bool>(s + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= s; j++)
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
    int mini = 1e9;
    for (int i = 0; i <= s; i++)
    {
        if (dp[n - 1][i])
        {
            int s1 = i;
            int s2 = s - s1;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}