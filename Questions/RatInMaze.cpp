#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>> maze, vector<vector<int>> visited, int n, int x, int y)
{
    // cout << "Entered isSafe: (x,y): (" << x << "," << y << ")" << endl;
    if (x < n && x >= 0 && y >= 0 && y < n && maze[x][y] == 1 && visited[x][y] == 0)
    {
        // cout << "isSafe TRUE, vale at maze: " << maze[x][y] << " Value of visited: " << visited[x][y] << endl;
        return true;
    }
    else
    {
        // cout << "isSafe FALSE" << endl;
        return false;
    }
}

void solve(vector<vector<int>> maze, vector<vector<int>> visited, int n, string output, int x, int y, vector<string> &ans)
{
    // we have reached x,y here
    // cout << "Entered solve function with (x,y): (" << x << "," << y << ")" << endl;
    if (x == n - 1 && y == n - 1)
    {
        // cout << "Entered base condition with path: " << output << endl;
        ans.push_back(output);
        return;
    }

    visited[x][y] = 1;
    // Down movement:
    if (isSafe(maze, visited, n, x + 1, y))
    {
        // cout << "Doing down movement, (x,y): (" << x + 1 << "," << y << ")" << endl;
        output.push_back('D');
        solve(maze, visited, n, output, x + 1, y, ans);
        output.pop_back();
    }

    // Left movement:
    if (isSafe(maze, visited, n, x, y - 1))
    {
        // cout << "Doing left movement, (x,y): (" << x << "," << y - 1 << ")" << endl;
        output.push_back('L');
        solve(maze, visited, n, output, x, y - 1, ans);
        output.pop_back();
    }

    // Right movement:
    if (isSafe(maze, visited, n, x, y + 1))
    {
        // cout << "Doing right movement, (x,y): (" << x << "," << y + 1 << ")" << endl;
        output.push_back('R');
        solve(maze, visited, n, output, x, y + 1, ans);
        output.pop_back();
    }

    // Up movement:
    if (isSafe(maze, visited, n, x - 1, y))
    {
        // cout << "Doing up movement, (x,y): (" << x - 1 << "," << y << ")" << endl;
        output.push_back('U');
        solve(maze, visited, n, output, x - 1, y, ans);
        output.pop_back();
    }
    visited[x][y] = 0;
}

vector<string> ratInMaze(vector<vector<int>> maze, int n)
{
    // cout << "Entered ratInMaze" << endl;
    vector<vector<int>> visited = maze;
    vector<string> ans;
    if (maze[0][0] == 0)
    {
        // cout << "Entered 0,0 condition in ratInMaze" << endl;
        return ans;
    }
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    // cout << "All visited marked 0" << endl;
    string output = "";
    solve(maze, visited, n, output, x, y, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int mazeSize = 4;
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                {1, 1, 0, 1},
                                {1, 1, 0, 0},
                                {0, 1, 1, 1}};
    vector<string> ans;
    ans = ratInMaze(maze, mazeSize);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}