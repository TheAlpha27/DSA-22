int solve(int ind, int tar, vector<int> &arr)
{
    if (ind < 0)
    {
        return 0;
    }
    if (ind == 0)
    {
        if (tar == 0 && arr[0] == 0)
        {
            return 2;
        }
        if (tar == arr[ind] || tar == 0)
        {
            return 1;
        }
    }
    int notPick = solve(ind - 1, tar, arr);
    int pick = 0;
    if (tar >= arr[ind])
    {
        pick = solve(ind - 1, tar - arr[ind], arr);
    }
    return pick + notPick;
}
int targetSum(int n, int target, vector<int> &arr)
{
    // Write your code here.
    int sum = 0;
    for (auto i : arr)
    {
        sum = sum + i;
    }
    if ((sum - target) % 2 != 0)
    {
        return 0;
    }
    int tar = (sum - target) / 2;
    return solve(n - 1, tar, arr);
}