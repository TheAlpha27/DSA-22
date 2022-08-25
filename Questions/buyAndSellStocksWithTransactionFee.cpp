int maximumProfit(int n, int fee, vector<int> &prices)
{
    // Write your code here.
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int flag = 0; flag <= 1; flag++)
        {
            if (flag)
            {
                dp[ind][flag] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            }
            else
            {
                dp[ind][flag] = max(prices[ind] - fee + dp[ind + 1][1], dp[ind + 1][0]);
            }
        }
    }
    return dp[0][1];
}