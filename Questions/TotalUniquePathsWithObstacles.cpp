#include <bits/stdc++.h>
#define mod 1000000007;
int solve(int i, int j, vector<vector<int>> &mat)
{

    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (mat[i][j] == -1)
    {
        return 0;
    }
    int up = solve(i - 1, j, mat) % mod;
    int left = solve(i, j - 1, mat) % mod;
    return (up + left) % mod;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    // Write your code here
    return solve(n - 1, m - 1, mat) % mod;
}

// Top_Down Approach
int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (mat[i][j] == -1)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = solve(i - 1, j, mat, dp) % mod;
    int left = solve(i, j - 1, mat, dp) % mod;
    return dp[i][j] = (up + left) % mod;
}
int mazeObstacles(int n, int m, vector<vector<int>> &mat)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return solve(n - 1, m - 1, mat, dp) % mod;
}

// Bottom_Up Approach
int solve(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    for (int k = 0; k <= i; k++)
    {
        for (int l = 0; l <= j; l++)
        {
            if (mat[k][l] == -1)
            {
                dp[k][l] = 0;
            }
            else if (k == 0 && l == 0)
            {
                dp[0][0] = 1;
            }
            else if (k == 0)
            {
                dp[k][l] = dp[k][l - 1] % mod;
            }
            else if (l == 0)
            {
                dp[k][l] = dp[k - 1][l] % mod;
            }
            else
            {
                dp[k][l] = (dp[k - 1][l] + dp[k][l - 1]) % mod;
            }
        }
    }
    return dp[i][j] % mod;
}