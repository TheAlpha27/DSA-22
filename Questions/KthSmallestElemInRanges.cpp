#include <bits/stdc++.h>
using namespace std;

int find(vector<vector<int>> range, int query)
{
    int rangeSize = 0;
    for (int i = 0; i < range.size(); i++)
    {
        rangeSize = range[i][1] - range[i][0] + 1;
        if (rangeSize > query)
        {
            return range[i][0] + query - 1;
        }
        if (rangeSize < query)
        {
            query = query - rangeSize;
        }
    }
    return -1;
}
vector<int> kthSmallestNum(vector<vector<int>> &range, vector<int> queries)
{
    // Write your code here
    vector<int> arr;
    for (int i = 0; i < queries.size(); i++)
    {
        int elem = find(range, queries[i]);
        arr.push_back(elem);
    }
    return arr;
}

int main()
{
    vector<vector<int>> range = {{1, 4}, {6, 8}};
    vector<int> queries = {2, 6, 10};
    vector<int> ans = kthSmallestNum(range, queries);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}