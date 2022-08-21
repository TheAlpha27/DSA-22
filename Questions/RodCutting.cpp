int solve(int ind, int w, vector<int> &price)
{
    if (w == 0)
    {
        return 0;
    }
    if (ind == 0)
    {
        return w * price[0];
    }
    int notPick = solve(ind - 1, w, price);
    int pick = -1e9;
    if (w >= (ind + 1))
    {
        pick = price[ind] + solve(ind, w - (ind + 1), price);
    }
    return max(pick, notPick);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    int size = price.size();
    return solve(size - 1, n, price);
}

// Top Down Approach
int solve(int ind, int w, vector<int> &price, vector<vector<int>> &dp)
{
    if (w == 0)
    {
        return 0;
    }
    if (ind == 0)
    {
        return w * price[0];
    }
    if (dp[ind][w] != -1)
    {
        return dp[ind][w];
    }
    int notPick = solve(ind - 1, w, price, dp);
    int pick = -1e9;
    if (w >= (ind + 1))
    {
        pick = price[ind] + solve(ind, w - (ind + 1), price, dp);
    }
    return dp[ind][w] = max(pick, notPick);
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    int size = price.size();
    vector<vector<int>> dp(size, vector<int>(n + 1, -1));
    return solve(size - 1, n, price, dp);
}