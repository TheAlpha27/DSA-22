// Basic Recursion, TC= O(3^n), SC = O(n)
int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid)
{
    if (i == r)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }
    if (j1 < 0 || j1 > c || j2 < 0 || j2 > c)
    {
        return -1e8;
    }
    int maxi = -1e8;
    for (int p1 = -1; p1 <= 1; p1++) // These loops will enable us to do all the 9 movements, otherwise we had to write them all separately, for every 1 movement of alice, bob have 3 moves. Alice have total 3 moves so there are 3*3 total moves in 1 iteration of row.
    {
        for (int p2 = -1; p2 <= 1; p2++)
        {
            if ((j1) == (j2))
            {
                maxi = max(maxi, grid[i][j1] + solve(i + 1, j1 + p1, j2 + p2, r, c, grid));
            }
            else
            {
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + p1, j2 + p2, r, c, grid));
            }
        }
    }
    return maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // Write your code here.
    return solve(0, 0, c - 1, r - 1, c - 1, grid);
}

// Top Down Approach
int solve(int i, int j1, int j2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 > c || j2 < 0 || j2 > c)
    {
        return -1e8;
    }
    if (i == r)
    {
        if (j1 == j2)
        {
            return grid[i][j1];
        }
        else
        {
            return grid[i][j1] + grid[i][j2];
        }
    }
    if (dp[i][j1][j2] != -1e8)
    {
        return dp[i][j1][j2];
    }
    int maxi = -1e8;
    for (int p1 = -1; p1 <= 1; p1++)
    {
        for (int p2 = -1; p2 <= 1; p2++)
        {
            if (j1 == j2)
            {
                maxi = max(maxi, grid[i][j1] + solve(i + 1, j1 + p1, j2 + p2, r, c, grid, dp));
            }
            else
            {
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + solve(i + 1, j1 + p1, j2 + p2, r, c, grid, dp));
            }
        }
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1e8)));
    return solve(0, 0, c - 1, r - 1, c - 1, grid, dp);
}

// Bottom_UP Approach
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1e8)));
    for (int j1 = 0; j1 < c; j1++) // base case when i == r
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                dp[r - 1][j1][j2] = grid[r - 1][j1];
            else
                dp[r - 1][j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }
    for (int i = r - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;
                for (int p1 = -1; p1 <= 1; p1++)
                {
                    for (int p2 = -1; p2 <= 1; p2++)
                    {
                        if (j1 == j2)
                        {
                            if (j1 + p1 < 0 || j1 + p1 >= c || j2 + p2 < 0 || j2 + p2 >= c)
                            {
                                continue;
                            }
                            else
                            {
                                maxi = max(maxi, grid[i][j1] + dp[i + 1][j1 + p1][j2 + p2]);
                            }
                        }
                        else
                        {
                            if (j1 + p1 < 0 || j1 + p1 >= c || j2 + p2 < 0 || j2 + p2 >= c)
                            {
                                continue;
                            }
                            else
                            {
                                maxi = max(maxi, grid[i][j1] + grid[i][j2] + dp[i + 1][j1 + p1][j2 + p2]);
                            }
                        }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][c - 1];
}

// Space Optimized to 2D dp
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    // Write your code here.
    vector<vector<int>> front(c, vector<int>(c, 0));
    for (int j1 = 0; j1 < c; j1++) // base case when i == r
    {
        for (int j2 = 0; j2 < c; j2++)
        {
            if (j1 == j2)
                front[j1][j2] = grid[r - 1][j1];
            else
                front[j1][j2] = grid[r - 1][j1] + grid[r - 1][j2];
        }
    }
    for (int i = r - 2; i >= 0; i--)
    {
        vector<vector<int>> curr(c, vector<int>(c, 0));
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                int maxi = -1e8;
                for (int p1 = -1; p1 <= 1; p1++)
                {
                    for (int p2 = -1; p2 <= 1; p2++)
                    {
                        if (j1 == j2)
                        {
                            if (j1 + p1 < 0 || j1 + p1 >= c || j2 + p2 < 0 || j2 + p2 >= c)
                            {
                                continue;
                            }
                            else
                            {
                                maxi = max(maxi, grid[i][j1] + front[j1 + p1][j2 + p2]);
                            }
                        }
                        else
                        {
                            if (j1 + p1 < 0 || j1 + p1 >= c || j2 + p2 < 0 || j2 + p2 >= c)
                            {
                                continue;
                            }
                            else
                            {
                                maxi = max(maxi, grid[i][j1] + grid[i][j2] + front[j1 + p1][j2 + p2]);
                            }
                        }
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][c - 1];
}