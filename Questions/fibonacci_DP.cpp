#include <bits/stdc++.h>
using namespace std;

// Top-Down approach
int fib(int n, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
}

// Bottom-Up Approach
int fib_tabulated(int n)
{
    if(n == 0)
    {
        return 0;
    }
    vector<int> dp(n);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

//Space optimized
int fib_SO(int n)
{
    int prev1 = 1;
    int prev2 = 0;
    if(n == 0)
    {
        return prev2;
    }
    for(int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << "1. Fibonacci number of " << n << " is: " << fib(n, dp) << endl;
    cout << "2. Fibonacci number of " << n << " is: " << fib_tabulated(n) << endl;
    cout << "3. Fibonacci number of " << n << " is: " << fib_SO(n) << endl;
    return 0;
}