int solve(int ind, int last, vector<vector<int>> &points)
{
    if (ind == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, points[ind][i]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    int meritPoints = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            meritPoints = points[ind][i] + solve(ind - 1, i, points);
            maxi = max(maxi, meritPoints);
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return solve(n - 1, 3, points);
}