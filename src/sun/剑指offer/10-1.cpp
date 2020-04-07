#include <bits/stdc++.h>
using namespace std;
//斐波那契数列
//input :5
//output:5
//注意题目要求对结果取模1000000007
int fib(int n)
{
    if (n == 0)
        return 0;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] % 1000000007 + dp[i - 2] % 1000000007;
    }
    return dp[n] % 1000000007;
}
int main()
{
    int n = 9;
    cout << fib(n);
    return 0;
}