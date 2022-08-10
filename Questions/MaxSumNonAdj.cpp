// Normal recursion
#include <bits/stdc++.h>
int solve(int ind, vector<int> &nums)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    int pick = nums[ind] + solve(ind - 2, nums);
    int notPick = 0 + solve(ind - 1, nums);
    return max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    return solve(nums.size() - 1, nums);
}

// Top_Down approach
int solve(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = nums[ind] + solve(ind - 2, nums, dp);
    int notPick = 0 + solve(ind - 1, nums, dp);
    return dp[ind] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums)
{
    // Write your code here.
    int size = nums.size();
    vector<int> dp(size, -1);
    return solve(size - 1, nums, dp);
}

// Bottom_Up Approach
int solve(int ind, vector<int> &nums, vector<int> &dp)
{
    dp[0] = nums[0];
    for (int i = 1; i <= ind; i++)
    {
        int pick;
        int notPick;
        if (i - 2 < 0)
        {
            pick = nums[i];
        }
        else
        {
            pick = nums[i] + dp[i - 2];
        }
        if (i - 1 < 0)
        {
            notPick = 0;
        }
        else
        {
            notPick = dp[i - 1];
        }
        dp[i] = max(pick, notPick);
    }
    return dp[ind];
}

//Space Optimized
int solve(int ind, vector<int> &nums)
{
    int prev1 = nums[0];
    int prev2 = 0;
    int curr = 0;;
    for(int i = 1; i <= ind; i++)
    {
        int pick;
        int notPick;
        
        if(i-2 < 0)
        {
            pick = nums[i];
        }
        else{
            pick = nums[i] + prev2;
        }
        if(i-1 < 0)
        {
            notPick = 0;
        }
        else{
            notPick = prev1;
        }
        curr = max(pick, notPick);
        prev2= prev1;
        prev1= curr;
    }
    return prev1;
}