int solve(int ind, int flag, int cap, vector<int> &val, int n, vector<vector<vector<int>>> &dp)
{
    if (cap == 0)
    {
        return 0;
    }
    if (ind == n)
    {
        return 0;
    }
    if (dp[ind][flag][cap] != -1)
    {
        return dp[ind][flag][cap];
    }
    if (flag)
    {
        return dp[ind][flag][cap] = max(-val[ind] + solve(ind + 1, 0, cap, val, n, dp), solve(ind + 1, 1, cap, val, n, dp));
    }
    else
    {
        return dp[ind][flag][cap] = max(val[ind] + solve(ind + 1, 1, cap - 1, val, n, dp), solve(ind + 1, 0, cap, val, n, dp));
    }
}
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k + 1, -1)));
    return solve(0, 1, k, prices, n, dp);
}