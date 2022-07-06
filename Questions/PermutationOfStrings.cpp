#include <bits/stdc++.h>
using namespace std;

void permutation(string str, int index, vector<string> &ans)
{
    if (index >= str.length())
    {
        ans.push_back(str);
        return;
    }
    for (int i = index; i < str.length(); i++)
    {
        swap(str[index], str[i]);
        permutation(str, index + 1, ans);
    }
}

int main()
{
    string str = "abc";
    int index = 0;
    vector<string> ans;
    permutation(str, index, ans);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}