int solve(int i, int j, int end, vector<vector<int>> &triangle)
{
    if (i == end || j == end)
    {
        return triangle[i][j];
    }
    if (i > end || j > i)
    {
        return 1e9;
    }
    int down = triangle[i][j] + solve(i + 1, j, end, triangle);
    int diag = triangle[i][j] + solve(i + 1, j + 1, end, triangle);
    return min(down, diag);
}
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    int end = triangle.size();
    return solve(0, 0, end - 1, triangle);
}

// Top_Down Approach
int solve(int i, int j, int end, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == end || j == end)
    {
        return dp[i][j] = triangle[i][j];
    }
    if (i > end || j > i)
    {
        return 1e9;
    }
    if (dp[i][j] != 1e9)
    {
        return dp[i][j];
    }
    int down = triangle[i][j] + solve(i + 1, j, end, triangle, dp);
    int diag = triangle[i][j] + solve(i + 1, j + 1, end, triangle, dp);
    return dp[i][j] = min(down, diag);
}

// Bottom_UP Approach
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    int end = triangle.size();
    vector<vector<int>> dp(end, vector<int>(end, 1e9));
    for (int i = end - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            if (i == end - 1)
            {
                dp[i][j] = triangle[i][j];
            }
            else
            {
                int up = triangle[i][j] + dp[i + 1][j];
                int diag = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(up, diag);
            }
        }
    }
    return dp[0][0];
}

// Space Optimized
int minimumPathSum(vector<vector<int>> &triangle, int n)
{
    // Write your code here.
    int end = triangle.size();
    vector<int> next(end, 1e9);
    for (int i = end - 1; i >= 0; i--)
    {
        vector<int> curr(end, 1e9);
        for (int j = i; j >= 0; j--)
        {
            if (i == end - 1)
            {
                curr[j] = triangle[i][j];
            }
            else
            {
                int up = triangle[i][j] + next[j];
                int diag = triangle[i][j] + next[j + 1];
                curr[j] = min(up, diag);
            }
        }
        next = curr;
    }
    return next[0];
}