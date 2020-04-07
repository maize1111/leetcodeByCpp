#include <bits/stdc++.h>
using namespace std;
//剪绳子
/*
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
*/
//贪心算法：尽量剪长度为三的段，如果最后一段为4的话剪为2+2
//动态规划：dp[i] = max(dp[i-j]*dp[j]) 需要存储子问题的最优解
int cuttingRope(int n)
{
    if (n <= 1)
        return n;
    if (n == 2)
        return 1;
    if (n == 3)
        return 2;
    vector<int> dp(n + 1, 0);
    dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3;
    for (int i = 4; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = max(dp[i], dp[i - j] * dp[j]);
        }
    }
    return dp[n];
}
int main()
{
    int n = 9;
    cout << cuttingRope(n);
    return 0;
}