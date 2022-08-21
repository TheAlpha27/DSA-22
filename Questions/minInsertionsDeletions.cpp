int canYouMake(string &str, string &ptr)
{
    // Write your code here.
    int l1 = str.length();
    int l2 = ptr.length();
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, -1));
    for (int i2 = 0; i2 <= l2; i2++)
    {
        dp[0][i2] = 0;
    }
    for (int i1 = 0; i1 <= l1; i1++)
    {
        dp[i1][0] = 0;
    }
    for (int i1 = 1; i1 <= l1; i1++)
    {
        for (int i2 = 1; i2 <= l2; i2++)
        {
            if (str[i1 - 1] == ptr[i2 - 1])
            {
                dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
            }
            else
            {
                dp[i1][i2] = max(dp[i1][i2 - 1], dp[i1 - 1][i2]);
            }
        }
    }
    int LCS = dp[l1][l2];
    int insertions = l2 - LCS;
    int deletions = l1 - LCS;
    return insertions + deletions;
}