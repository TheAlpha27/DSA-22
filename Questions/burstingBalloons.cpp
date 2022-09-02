int solve(int i, int j, vector<int> &arr)
{
    if (i > j)
    {
        return 0;
    }
    int maxi = -1e9;
    for (int k = i; k <= j; k++)
    {
        int points = arr[i - 1] * arr[k] * arr[j + 1] + solve(i, k - 1, arr) + solve(k + 1, j, arr);
        maxi = max(maxi, points);
    }
    return maxi;
}
int maxCoins(vector<int> &a)
{
    // Write your code here.
    int n = a.size();
    vector<int> arr;
    arr.push_back(1);
    for (auto i : a)
    {
        arr.push_back(i);
    }
    arr.push_back(1);
    return solve(1, n, arr);
}

// Top Down Approach
int solve(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int maxi = -1e9;
    for (int k = i; k <= j; k++)
    {
        int points = arr[i - 1] * arr[k] * arr[j + 1] + solve(i, k - 1, arr, dp) + solve(k + 1, j, arr, dp);
        maxi = max(maxi, points);
    }
    return dp[i][j] = maxi;
}
int maxCoins(vector<int> &a)
{
    // Write your code here.
    int n = a.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
    vector<int> arr;
    arr.push_back(1);
    for (auto i : a)
    {
        arr.push_back(i);
    }
    arr.push_back(1);
    return solve(1, n, arr, dp);
}