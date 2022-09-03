int solve(int i, int k, int n, vector<int> &num)
{
    if (i == n)
        return 0;
    int len = 0;
    int maxSum = -1e9;
    int maxElem = -1e9;
    for (int j = i; j < min(n, i + k); j++)
    {
        len++;
        maxElem = max(maxElem, num[j]);
        int sum = len * maxElem + solve(j + 1, k, n, num);
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}
int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.
    int n = num.size();
    return solve(0, k, n, num);
}

// Top Down
int solve(int i, int k, int n, vector<int> &num, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int len = 0;
    int maxSum = -1e9;
    int maxElem = -1e9;
    for (int j = i; j < min(n, i + k); j++)
    {
        len++;
        maxElem = max(maxElem, num[j]);
        int sum = len * maxElem + solve(j + 1, k, n, num, dp);
        maxSum = max(sum, maxSum);
    }
    return dp[i] = maxSum;
}
int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.
    int n = num.size();
    vector<int> dp(n, -1);
    return solve(0, k, n, num, dp);
}