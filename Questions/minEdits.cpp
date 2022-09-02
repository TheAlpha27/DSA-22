int LCS(int i1, int i2, string s1, string s2)
{
    if (i1 < 0 && i2 < 0)
    {
        return 0;
    }
    if (i1 < 0 && i2 >= 0)
    {
        return i2 + 1;
    }
    if (i1 >= 0 && i2 < 0)
    {
        return i1 + 1;
    }
    if (s1[i1] == s2[i2])
        return LCS(i1 - 1, i2 - 1, s1, s2);
    if (s1[i1] != s2[i2])
    {
        int rep = 1 + LCS(i1 - 1, i2 - 1, s1, s2);
        int del = 1 + LCS(i1 - 1, i2, s1, s2);
        int ins = 1 + LCS(i1, i2 - 1, s1, s2);
        return min(rep, min(del, ins));
    }
}
int editDistance(string str1, string str2)
{
    // write you code here
    int l1 = str1.length();
    int l2 = str2.length();
    return LCS(l1 - 1, l2 - 1, str1, str2);
}

// BottomUP Approach
int editDistance(string str1, string str2)
{
    // write you code here
    int l1 = str1.length();
    int l2 = str2.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    dp[0][0] = 0;
    for (int i2 = 1; i2 <= l2; i2++)
    {
        dp[0][i2] = i2;
    }
    for (int i1 = 1; i1 <= l1; i1++)
    {
        dp[i1][0] = i1;
    }
    for (int i1 = 1; i1 <= l1; i1++)
    {
        for (int i2 = 1; i2 <= l2; i2++)
        {
            if (str1[i1 - 1] == str2[i2 - 1])
            {
                dp[i1][i2] = dp[i1 - 1][i2 - 1];
            }
            else
            {
                int rep = 1 + dp[i1 - 1][i2 - 1];
                int del = 1 + dp[i1 - 1][i2];
                int ins = 1 + dp[i1][i2 - 1];
                dp[i1][i2] = min(rep, min(del, ins));
            }
        }
    }
    return dp[l1][l2];
}