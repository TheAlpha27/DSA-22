#define lli long long int
lli solve(lli ind, vector<int> &valueInHouse)
{
    lli size = valueInHouse.size();
    int curr = 0;
    int prev1 = 0;
    int prev2 = 0;
    if (ind == size - 2)
    {
        prev1 = valueInHouse[0];
        for (lli i = 1; i <= ind; i++)
        {
            lli pick;
            lli notPick;
            if (i - 2 < 0)
            {
                pick = valueInHouse[i];
            }
            else
            {
                pick = valueInHouse[i] + prev2;
            }
            if (i - 1 < 0)
            {
                notPick = 0;
            }
            else
            {
                notPick = prev1;
            }
            curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
    else
    {
        prev1 = valueInHouse[1];
        for (lli i = 2; i <= ind; i++)
        {
            lli pick;
            lli notPick;
            if (i - 2 < 0)
            {
                pick = valueInHouse[i];
            }
            else
            {
                pick = valueInHouse[i] + prev2;
            }
            if (i - 1 < 0)
            {
                notPick = 0;
            }
            else
            {
                notPick = prev1;
            }
            curr = max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
}
long long int houseRobber(vector<int> &valueInHouse)
{
    // Write your code here.
    lli size = valueInHouse.size();
    if (size == 1)
    {
        return valueInHouse[0];
    }
    lli ans1 = solve(size - 2, valueInHouse); // last house ignored
    lli ans2 = solve(size - 1, valueInHouse); // first house ignored
    return max(ans1, ans2);
}