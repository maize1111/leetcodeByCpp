#include <bits/stdc++.h>
using namespace std;
//青蛙跳台阶问题：一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
//注意题目要求对结果取模1000000007
int numWays(int n) {
    if (n<=1)
        return 1;
    if(n==2) return 2;
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] % 1000000007 + dp[i - 2] % 1000000007;
    }
    return dp[n] % 1000000007;

}
    
int main()
{
    int n = 9;
    cout << numWays(n);
    return 0;
}