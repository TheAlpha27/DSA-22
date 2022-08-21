int lcs(string &s, string &t)
{
    //	Write your code here.
    int ind1 = s.length();                                      // ind1 = 0 means index = -1 (according to top down approach)
    int ind2 = t.length();                                      // ind2 ,, ,, ,, ......
    vector<vector<int>> dp(ind1 + 1, vector<int>(ind2 + 1, 0)); // increase the size of the dp
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
    int ans = 0;
    for (int i1 = 1; i1 <= ind1; i1++)
    {
        for (int i2 = 1; i2 <= ind2; i2++)
        {
            if (s[i1 - 1] == t[i2 - 1])
            {
                dp[i1][i2] = 1 + dp[i1 - 1][i2 - 1];
                ans = max(ans, dp[i1][i2]);
            }
            else
            {
                dp[i1][i2] = 0;
            }
        }
    }
    return ans;
}