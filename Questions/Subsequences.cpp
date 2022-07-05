#include <bits/stdc++.h>
using namespace std;

void solve(string str, string output, vector<string> &ans, int index)
{
    // cout<<"Entered solve"<<endl;
    if (index >= str.length())
    {
        // cout << "Entered base condition with output as: " << output << endl;
        if (output == "")
        {
            return;
        }
        ans.push_back(output);
        return;
    }
    // handling exclude
    solve(str, output, ans, index+1);

    // handling include
    char elem = str[index];
    // cout << "Handling include with character: " << elem << endl;
    output.push_back(elem);
    solve(str, output, ans, index+1);
}

vector<string> subsequences(string str)
{
    // cout << "Entered subsequences" << endl;
    int index = 0;
    string output = "";
    vector<string> ans;
    solve(str, output, ans, index);
    return ans;
}

int main()
{
    string str = "abc";
    vector<string> ans;
    ans = subsequences(str);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}