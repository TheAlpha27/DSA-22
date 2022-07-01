#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> bubbleSort(vector<int> v)
{
    int lastInd = v.size() - 1;
    while (lastInd != 0)
    {
        for (int i = 0; i < lastInd; i++)
        {
            if (v[i] > v[i + 1])
            {
                swap(v[i], v[i + 1]);
            }
        }
        lastInd--;
    }
    return v;
}

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(6);
    v.push_back(10);
    v.push_back(5);
    v.push_back(10);
    v.push_back(0);
    v.push_back(23);
    v.push_back(18);
    cout << "Before Sort:" << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    v = bubbleSort(v);
    cout << "After Sort:" << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}