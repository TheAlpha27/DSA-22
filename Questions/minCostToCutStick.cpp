#include <bits/stdc++.h>
int solve(int i, int j, vector<int> &cuts)
{
    if (i > j)
        return 0;
    int mini = 1e9;
    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solve(i, k - 1, cuts) + solve(k + 1, j, cuts);
        mini = min(mini, cost);
    }
    return mini;
}
int cost(int n, int c, vector<int> &cuts)
{
    // Write your code here.
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    return solve(1, c, cuts);
}

// Top Down Approach
#include <bits/stdc++.h>
int solve(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int k = i; k <= j; k++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solve(i, k - 1, cuts, dp) + solve(k + 1, j, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[i][j] = mini;
}
int cost(int n, int c, vector<int> &cuts)
{
    // Write your code here.
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, -1));
    return solve(1, c, cuts, dp);
}