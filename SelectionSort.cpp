#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> v)
{
    int startInd = 0;
    int minInd = 0;
    while (startInd != v.size())
    {
        int min = v[startInd];
        for (int i = startInd + 1; i < v.size(); i++)
        {
            if (min > v[i])
            {
                min = v[i];
                minInd = i;
            }
        }
        v[minInd] = v[startInd];
        v[startInd] = min;
        startInd++;
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
    v = selectionSort(v);
    cout << "After Sort" << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}