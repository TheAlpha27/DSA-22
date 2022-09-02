int solve(int i, int j, bool isTrue, string &exp)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        else
        {
            return exp[i] == 'F';
        }
    }
    int ways = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        int lt = solve(i, k - 1, 1, exp);
        int lf = solve(i, k - 1, 0, exp);
        int rt = solve(k + 1, j, 1, exp);
        int rf = solve(k + 1, j, 0, exp);
        if (exp[k] == '&')
        {
            if (isTrue)
            {
                ways += lt * rt;
            }
            else
            {
                ways += lt * rf + lf * rt + lf * rf;
            }
        }
        else if (exp[k] == '|')
        {
            if (isTrue)
            {
                ways += lt * rt + lf * rt + lt * rf;
            }
            else
            {
                ways += lf * rf;
            }
        }
        else if (exp[k] == '^')
        {
            if (isTrue)
            {
                ways += lt * rf + lf * rt;
            }
            else
            {
                ways += lt * rt + lf * rf;
            }
        }
    }
    return ways;
}
int evaluateExp(string &exp)
{
    // Write your code here.
    int n = exp.length();
    return solve(0, n - 1, 1, exp);
}

// Top Down
int mod = 1000000007;
long long solve(int i, int j, bool isTrue, string &exp, vector<vector<vector<long long>>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (i == j)
    {
        if (isTrue)
        {
            return exp[i] == 'T';
        }
        else
        {
            return exp[i] == 'F';
        }
    }
    if (dp[i][j][isTrue] != -1)
    {
        return dp[i][j][isTrue];
    }
    long long ways = 0;
    for (int k = i + 1; k <= j - 1; k = k + 2)
    {
        long long lt = solve(i, k - 1, 1, exp, dp) % mod;
        long long lf = solve(i, k - 1, 0, exp, dp) % mod;
        long long rt = solve(k + 1, j, 1, exp, dp) % mod;
        long long rf = solve(k + 1, j, 0, exp, dp) % mod;
        if (exp[k] == '&')
        {
            if (isTrue)
            {
                ways += lt * rt % mod;
            }
            else
            {
                ways += lt * rf % mod + lf * rt % mod + lf * rf % mod;
            }
        }
        else if (exp[k] == '|')
        {
            if (isTrue)
            {
                ways += lt * rt % mod + lf * rt % mod + lt * rf % mod;
            }
            else
            {
                ways += lf * rf % mod;
            }
        }
        else if (exp[k] == '^')
        {
            if (isTrue)
            {
                ways += lt * rf % mod + lf * rt % mod;
            }
            else
            {
                ways += lt * rt % mod + lf * rf % mod;
            }
        }
    }
    return dp[i][j][isTrue] = ways % mod;
}
int evaluateExp(string &exp)
{
    // Write your code here.
    int n = exp.length();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return solve(0, n - 1, 1, exp, dp);
}