int stockProfit(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    int k = 2;
    vector<vector<int>> dp(n + k, vector<int>(2, -1));
    for (int i = n; i < n + k; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 0;
    }
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
                dp[ind][flag] = max(prices[ind] + dp[ind + k][1], dp[ind + 1][0]);
            }
        }
    }
    return dp[0][1];
}