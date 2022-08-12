#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    int up = solve(i - 1, j);
    int left = solve(i, j - 1);
    return up + left;
}
int main()
{
    // Write your code here.
    int m = 3;
    int n = 3;
    cout << solve(m - 1, n - 1) << endl;
    return 0;
}

// Top_Down Approach
int solve(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (i < 0 || j < 0)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int up = solve(i - 1, j, dp);
    int left = solve(i, j - 1, dp);
    return dp[i][j] = up + left;
}

// Bottom_UP Approach
int solve(int i, int j, vector<vector<int>> &dp)
{
    for (int k = 0; k <= i; k++)
    {
        for (int l = 0; l <= j; l++)
        {
            if (k == 0 && l == 0)
            {
                dp[0][0] = 1;
            }
            else
            {
                if (k - 1 < 0)
                {
                    dp[k][l] = 0 + dp[k][l - 1];
                }
                else if (l - 1 < 0)
                {
                    dp[k][l] = dp[k - 1][l] + 0;
                }
                else
                {
                    dp[k][l] = dp[k - 1][l] + dp[k][l - 1];
                }
            }
        }
    }
    return dp[i][j];
}

// Space optimized
int solve(int i, int j, vector<vector<int>> &dp)
{
    vector<int> prev(j + 1, -1);
    for (int k = 0; k <= i; k++)
    {
        vector<int> curr(j + 1, -1);
        for (int l = 0; l <= j; l++)
        {
            if (k == 0 && l == 0)
            {
                curr[l] = 1;
            }
            else if (k == 0)
            {
                curr[l] = curr[l - 1];
            }
            else if (l - 1 < 0)
            {
                curr[l] = prev[l];
            }
            else
            {
                curr[l] = prev[l] + curr[l - 1];
            }
        }
        prev = curr;
    }
    return prev[j];
}