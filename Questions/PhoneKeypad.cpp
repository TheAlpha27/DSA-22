#include <bits/stdc++.h>
using namespace std;

void solve(string inp, string output, vector<string> &ans, int index1, int index2, vector<string> arr)
{

    // cout << "Entered Solve, value of Index1: " << index1 << " and index2: " << index2 << endl;

    if (index1 >= inp.length())
    {

        // cout << "Entered base condition with output: " << output << endl;

        if (output.length() == inp.length())
        {

            // cout << output << " is being pushed in ans" << endl;

            ans.push_back(output);
        }
        return;
    }
    int ind = inp[index1] - '0'; // returns the digit pointed by index1 in inp string
    string elemStr = arr[ind];   // returns the string assinged to the digit
    if (index2 < elemStr.length())
    {
        char elem = elemStr[index2]; // returns the element of that string

        // cout << "Entered if condition with element being pushed in output: " << elem << ", index2: " << index2 << " and index1: " << index1 << endl;

        solve(inp, output, ans, index1, index2 + 1, arr);
        output.push_back(elem);

        // cout << "Value of output: " << output << endl;
    }
    index2 = 0;
    solve(inp, output, ans, index1 + 1, index2, arr);
}

vector<string> phoneKeypad(string inp, vector<string> arr)
{
    int index1 = 0;
    int index2 = 0;
    string output = "";
    vector<string> ans;
    if (inp == "")
    {
        return ans;
    }
    solve(inp, output, ans, index1, index2, arr);
    return ans;
}

int main()
{
    vector<string> arr = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string inp = "92";
    vector<string> ans;
    ans = phoneKeypad(inp, arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}