#include <bits/stdc++.h>
int solve(int i, int j, vector<vector<int>> &grid)
{
    if (i == 0 && j == 0)
    {
        return grid[0][0];
    }
    if (i < 0 || j < 0)
    {
        return 1e9;
    }
    int up = grid[i][j] + solve(i - 1, j, grid);
    int left = grid[i][j] + solve(i, j - 1, grid);
    return min(up, left);
}
int minSumPath(vector<vector<int>> &grid)
{
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    return solve(n - 1, m - 1, grid);
}

// Top_Down Approach
#include <bits/stdc++.h>
int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return dp[0][0] = grid[0][0];
    }
    if (i < 0 || j < 0)
    {
        return 1e9;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = grid[i][j] + solve(i - 1, j, grid, dp);
    int left = grid[i][j] + solve(i, j - 1, grid, dp);
    return dp[i][j] = min(up, left);
}

// Bottom_UP Approach
int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    for (int k = 0; k <= i; k++)
    {
        for (int l = 0; l <= j; l++)
        {
            if (k == 0 && l == 0)
            {
                dp[0][0] = grid[0][0];
            }
            else if (k == 0)
            {
                dp[k][l] = grid[k][l] + dp[k][l - 1];
            }
            else if (l == 0)
            {
                dp[k][l] = grid[k][l] + dp[k - 1][l];
            }
            else
            {
                dp[k][l] = min(grid[k][l] + dp[k - 1][l], grid[k][l] + dp[k][l - 1]);
            }
        }
    }
    return dp[i][j];
}

// Space Optimized
int solve(int i, int j, vector<vector<int>> &grid)
{
    vector<int> prev(j + 1, -1);
    for (int k = 0; k <= i; k++)
    {
        vector<int> curr(j + 1, -1);
        for (int l = 0; l <= j; l++)
        {
            if (k == 0 && l == 0)
            {
                curr[l] = grid[0][0];
            }
            else if (k == 0)
            {
                curr[l] = grid[k][l] + curr[l - 1];
            }
            else if (l == 0)
            {
                curr[l] = grid[k][l] + prev[l];
            }
            else
            {
                curr[l] = min(grid[k][l] + prev[l], grid[k][l] + curr[l - 1]);
            }
        }
        prev = curr;
    }
    return prev[j];
}