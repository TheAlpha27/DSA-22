#include <bits/stdc++.h>
using namespace std;

int calculate(int nStairs)
{
    if (nStairs < 0)
    {
        return 0;
    }
    if (nStairs == 0)
    {
        return 1;
    }
    return calculate(nStairs - 1) + calculate(nStairs - 2);
}

int main()
{
    int nStairs;
    cin >> nStairs;

    cout << calculate(nStairs) << endl;

    return 0;
}