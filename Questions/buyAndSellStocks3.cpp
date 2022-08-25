int solve(int ind, bool flag, int cap, vector<int> &val, int n, vector<vector<vector<int>>> &dp)
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
int maxProfit(vector<int> &prices, int n)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(0, 1, 2, prices, n, dp);
}