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

// Top_Down approach
int solve(int ind, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (dp[ind][last] != -1)
    {
        return dp[ind][last];
    }
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
        return dp[ind][last] = maxi;
    }
    int maxi = 0;
    int meritPoints = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            meritPoints = points[ind][i] + solve(ind - 1, i, points, dp);
            maxi = max(maxi, meritPoints);
        }
    }
    return dp[ind][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 3, points, dp);
}

// Bottom_UP Approach
int solve(int ind, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    for (int day = 0; day <= ind; day++)
    {
        if (day == 0)
        {
            dp[0][0] = max(points[0][1], points[0][2]);
            dp[0][1] = max(points[0][0], points[0][2]);
            dp[0][2] = max(points[0][1], points[0][0]);
            dp[0][3] = max(points[0][1], max(points[0][2], points[0][0]));
        }
        else
        {
            for (int last = 0; last <= 3; last++)
            {
                dp[day][last] = 0;
                for (int task = 0; task <= 2; task++)
                {
                    if (task != last)
                    {
                        int point = points[day][task] + dp[day - 1][task];
                        dp[day][last] = max(dp[day][last], point);
                    }
                }
            }
        }
    }
    return dp[ind][last];
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(n - 1, 3, points, dp);
}

// space optimised
int solve(int ind, int last, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    for (int day = 0; day <= ind; day++)
    {
        if (day == 0)
        {
            prev[0] = max(points[0][1], points[0][2]);
            prev[1] = max(points[0][0], points[0][2]);
            prev[2] = max(points[0][1], points[0][0]);
            prev[3] = max(points[0][1], max(points[0][2], points[0][0]));
        }
        else
        {
            vector<int> temp(4, 0);
            for (int last = 0; last <= 3; last++)
            {
                for (int task = 0; task <= 2; task++)
                {
                    if (task != last)
                    {
                        int point = points[day][task] + prev[task];
                        temp[last] = max(temp[last], point);
                    }
                }
            }
            prev = temp;
        }
    }
    return prev[last];
}