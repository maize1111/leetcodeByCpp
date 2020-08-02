#include <bits/stdc++.h>
using namespace std;
int getMoneyAmount(int n)
{
    //动态规划问题
    //极小化极大问题
    //dp[i][j]表示从[i,j]中猜出正确数据花费的最小金额
    //在[i,j]中选择x花费的最小金额为max(dp[i][x-1], dp[x+1][j]) + x
    //用max的原因是我们要计算最坏反馈情况下的最少花费金额(选了x之后, 正确数字落在花费更高的那侧
    //最终花费的最小金额应是x在[i,j]中的所有情况中的最小花费使用min即可
    //初始化dp大小为n+2的目的是便于处理边界情况
    //需要注意x和y的更新顺序，保证计算新的元素时，之前的元素已经填入数字
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j <= n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INT_MAX;
                for (int x = i; x <= j; x++)
                {
                    dp[i][j] = min(max(dp[i][x - 1], dp[x + 1][j]) + x, dp[i][j]);
                }
            }
        }
    }
    
    return dp[1][n];
}

int main()
{
    int n = 10;
    cout << getMoneyAmount(n) << endl;
    return 0;
}