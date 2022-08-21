int solve(int ind1, int ind2, string s, string t)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }
    if (s[ind1] == t[ind2])
    {
        return 1 + solve(ind1 - 1, ind2 - 1, s, t);
    }
    else
    {
        return max(solve(ind1 - 1, ind2, s, t), solve(ind1, ind2 - 1, s, t));
    }
}
int lcs(string s, string t)
{
    // Write your code here
    int ind1 = s.length() - 1;
    int ind2 = t.length() - 1;
    return solve(ind1, ind2, s, t);
}

// Top Down Approach
#include <bits/stdc++.h>
int solve(int ind1, int ind2, string s, string t, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
    {
        return 0;
    }
    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }
    if (s[ind1] == t[ind2])
    {
        return dp[ind1][ind2] = 1 + solve(ind1 - 1, ind2 - 1, s, t, dp);
    }
    else
    {
        return dp[ind1][ind2] = max(solve(ind1 - 1, ind2, s, t, dp), solve(ind1, ind2 - 1, s, t, dp));
    }
}
int lcs(string s, string t)
{
    // Write your code here
    int ind1 = s.length() - 1;
    int ind2 = t.length() - 1;
    vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, -1));
    return solve(ind1, ind2, s, t, dp);
}

// For tabulation, we will right shift the indexes.
#include <bits/stdc++.h>
int lcs(string s, string t)
{
    // Write your code here
    int ind1 = s.length();                                      // ind1 = 0 means index = -1 (according to top down approach)
    int ind2 = t.length();                                      // ind2 ,, ,, ,, ......
    vector<vector<int>> dp(ind1 + 2, vector<int>(ind2 + 2, 0)); // increase the size of the dp

    // Base Cases
    // i1 < 0
    for (int i2 = 0; i2 <= ind2; i2++)
    {
        dp[0][i2] = 0;
    }
    // i2 < 0
    for (int i1 = 0; i1 <= ind1; i1++)
    {
        dp[i1][0] = 0;
    }

    for (int i1 = 1; i1 <= ind1; i1++)
    {
        for (int i2 = 1; i2 <= ind2; i2++)
        {
            if (s[i1 - 1] == t[i2 - 1])
            {
                dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
            }
            else
            {
                dp[i1][i2] = max(dp[i1 - 1][i2], dp[i1][i2 - 1]);
            }
        }
    }
    return dp[ind1][ind2];
}