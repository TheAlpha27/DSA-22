#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> v)
{
    int partition = 1;
    int minElem;
    int minFound;
    int minInd; //index where the minimum element goes after being sorted
    while (partition != v.size())
    {
        minFound = 0;
        minElem = v[partition];
        minInd = 0;
        for (int i = partition - 1; i >= 0; i--)
        {
            if(v[partition] <= v[i] && i == 0){
                minElem = v[partition];
                minFound = 1;
                minInd = i;
                // cout<<"Min elem is: "<<minElem<<" at index: "<<partition<<" to be placed at index: "<<minInd<<endl;
            }
            if (v[partition] <= v[i] && v[partition] >= v[i-1])
            {
                minElem = v[partition];
                minFound = 1;
                minInd = i;
                // cout<<"Min elem is: "<<minElem<<" at index: "<<partition<<" to be placed at index: "<<minInd<<endl;
            }
        }
        if (minFound)
        {
            for (int i = partition; i > minInd; i--)
            {
                // cout<<v[i-1]<<" at index: "<<i-1<<" shifting to index: "<<i<<" where initially the value is: "<<v[i]<<endl;
                v[i] = v[i - 1];
            }
            v[minInd] = minElem;
        }
        partition++;
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
    v = insertionSort(v);
    cout << "After Sort:" << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}