#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, vector<int> output, vector<vector<int>> &ans, int index)
{
    // cout<<"Entered solve function"<<endl;
    if (index >= nums.size())
    {
        // cout<<"Entered base case with index value: "<<index<<endl;
        ans.push_back(output);
        return;
    }
    // excluding case
    solve(nums, output, ans, index+1);

    // including case
    int element = nums[index];
    // cout<<"Including case element: "<<element<<endl;
    output.push_back(element);
    solve(nums, output, ans, index+1);
}

vector<vector<int>> subsets(vector<int> &nums)
{
    int index = 0;
    vector<vector<int>> ans;
    vector<int> output;
    // cout<<"Entered Subsets function"<<endl;
    solve(nums, output, ans, index);
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans = subsets(nums);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}