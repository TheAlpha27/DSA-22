#include <bits/stdc++.h>
int solve(int i1, int i2, string s1, string s2, vector<vector<int>> &dp)
{
    if (i1 < 0 || i2 < 0)
    {
        return 0;
    }
    if (dp[i1][i2] != -1)
    {
        return dp[i1][i2];
    }
    if (s1[i1] == s2[i2])
    {
        return dp[i1][i2] = 1 + solve(i1 - 1, i2 - 1, s1, s2, dp);
    }
    else
    {
        return dp[i1][i2] = max(solve(i1 - 1, i2, s1, s2, dp), solve(i1, i2 - 1, s1, s2, dp));
    }
}
int minInsertion(string &str)
{
    // Write your code here.
    string s = str;
    int len = str.length();
    for (int i = 0; i < len / 2; i++)
    {
        swap(s[len - i - 1], s[i]);
    }
    vector<vector<int>> dp(len, vector<int>(len, -1));
    int count = len - solve(len - 1, len - 1, s, str, dp);
    return count;
}