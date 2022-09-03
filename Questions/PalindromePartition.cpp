bool isPal(string str)
{
    int n = str.length();
    bool pal = true;
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
        {
            pal = false;
            return pal;
        }
    }
    return pal;
}
int solve(int i, int n, string &str)
{
    if (i == n)
        return 0;
    int mini = 1e9;
    string temp = "";
    for (int j = i; j < n; j++)
    {
        temp += str[j];
        if (isPal(temp))
        {
            int cost = 1 + solve(j + 1, n, str);
            mini = min(mini, cost);
        }
    }
    return mini;
}
int palindromePartitioning(string str)
{
    // Write your code here
    int n = str.length();
    return solve(0, n, str) - 1;
}

// Top Down approach
#include <bits/stdc++.h>
bool isPal(string str)
{
    int n = str.length();
    bool pal = true;
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - i - 1])
        {
            pal = false;
            return pal;
        }
    }
    return pal;
}
int solve(int i, int n, string &str, vector<int> &dp)
{
    if (i == n)
        return 0;
    int mini = 1e9;
    if (dp[i] != -1)
        return dp[i];
    string temp = "";
    for (int j = i; j < n; j++)
    {
        temp += str[j];
        if (isPal(temp))
        {
            int cost = 1 + solve(j + 1, n, str, dp);
            mini = min(mini, cost);
        }
    }
    return dp[i] = mini;
}
int palindromePartitioning(string str)
{
    // Write your code here
    int n = str.length();
    vector<int> dp(n, -1);
    return solve(0, n, str, dp) - 1;
}
