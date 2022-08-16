bool solve(vector<int> &arr, int ind, int target)
{
    if (target == 0)
    {
        return true;
    }
    if (ind == 0)
    {
        if (arr[ind] == target)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
    bool notPick = solve(arr, ind - 1, target);
    bool pick = false;
    if (target >= arr[ind])
    {
        pick = solve(arr, ind - 1, target - arr[ind]);
    }
    return pick || notPick;
}
bool canPartition(vector<int> &arr, int n)
{
    // Write your code here.
    int sum = 0;
    for (auto i : arr)
    {
        sum = sum + i;
    }
    if (sum % 2 == 0)
        return solve(arr, n - 1, sum / 2);
    else
    {
        return false;
    }
}

// Top_Down Approach
bool solve(vector<int> &arr, int ind, int target, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }
    if (ind == 0)
    {
        if (arr[ind] == target)
        {
            return true;
        }

        else
        {
            return false;
        }
    }
    if (dp[ind][target] != -1)
    {
        return dp[ind][target];
    }
    bool notPick = solve(arr, ind - 1, target, dp);
    bool pick = false;
    if (target >= arr[ind])
    {
        pick = solve(arr, ind - 1, target - arr[ind], dp);
    }
    return dp[ind][target] = pick || notPick;
}