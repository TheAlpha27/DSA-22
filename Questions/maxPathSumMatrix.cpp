// Top_Down Approach --- gives TLE   TC = O(col * row) it gives tle because recursion fills up the stack and creates copies of the parameters which consumes time
int solve(int i, int j, int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (j > col || j < 0)
    {
        return -1e9;
    }
    if (i == 0)
    {
        return dp[i][j] = matrix[i][j];
    }
    if (dp[i][j] != -1e9)
    {
        return dp[i][j];
    }
    int up = matrix[i][j] + solve(i - 1, j, row, col, matrix, dp);
    int ur = matrix[i][j] + solve(i - 1, j + 1, row, col, matrix, dp);
    int ul = matrix[i][j] + solve(i - 1, j - 1, row, col, matrix, dp);
    return dp[i][j] = max(up, max(ur, ul));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int row = matrix.size() - 1;
    int col = matrix[0].size() - 1;
    int max = -1e9;
    for (int j = 0; j <= col; j++)
    {
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1e9));
        int ans = solve(row, j, row, col, matrix, dp);
        if (ans > max)
        {
            max = ans;
        }
    }
    return max;
}

// Bottom_UP Approach --- doesn't gives TLE   TC = O(row*col) + O(col)
int solve(int row, int col, vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, -1e9));
    for (int i = 0; i <= row; i++)
    {
        for (int j = 0; j <= col; j++)
        {
            if (i == 0)
            {
                dp[i][j] = matrix[i][j];
            }
            else if (j - 1 < 0)
            {
                int down = matrix[i][j] + dp[i - 1][j];
                int dl = matrix[i][j] + dp[i - 1][j + 1];
                dp[i][j] = max(down, dl);
            }
            else if (j + 1 > col)
            {
                int down = matrix[i][j] + dp[i - 1][j];
                int dr = matrix[i][j] + dp[i - 1][j - 1];
                dp[i][j] = max(down, dr);
            }
            else
            {
                int down = matrix[i][j] + dp[i - 1][j];
                int dl = matrix[i][j] + dp[i - 1][j + 1];
                int dr = matrix[i][j] + dp[i - 1][j - 1];
                dp[i][j] = max(down, max(dr, dl));
            }
        }
    }
    int maxi = -1e9;
    for (int j = 0; j <= col; j++)
    {
        maxi = max(maxi, dp[row][j]);
    }
    return maxi;
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int row = matrix.size() - 1;
    int col = matrix[0].size() - 1;
    return solve(row, col, matrix);
}

// Space Optimized
int solve(int row, int col, vector<vector<int>> &matrix)
{
    //     vector<vector<int>> dp(row+1, vector<int> (col+1, -1e9));
    vector<int> prev(col + 1, -1);
    for (int i = 0; i <= row; i++)
    {
        vector<int> curr(col + 1, -1);
        for (int j = 0; j <= col; j++)
        {
            if (i == 0)
            {
                curr[j] = matrix[i][j];
            }
            else if (j - 1 < 0)
            {
                int down = matrix[i][j] + prev[j];
                int dl = matrix[i][j] + prev[j + 1];
                curr[j] = max(down, dl);
            }
            else if (j + 1 > col)
            {
                int down = matrix[i][j] + prev[j];
                int dr = matrix[i][j] + prev[j - 1];
                curr[j] = max(down, dr);
            }
            else
            {
                int down = matrix[i][j] + prev[j];
                int dl = matrix[i][j] + prev[j + 1];
                int dr = matrix[i][j] + prev[j - 1];
                curr[j] = max(down, max(dr, dl));
            }
        }
        prev = curr;
    }
    int maxi = -1e9;
    for (int j = 0; j <= col; j++)
    {
        maxi = max(maxi, prev[j]);
    }
    return maxi;
}