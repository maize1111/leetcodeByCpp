#include <bits/stdc++.h>
using namespace std;
int minDistance(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();
    //有空串
    if (m * n == 0)
        return m + n;
    //dp[i][j] 表示 A 的前 i 个字母和 B 的前 j 个字母之间的编辑距离。
    //初始化dp的0行和0列
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = i;
    }
    //只有三种操作：A中插入一个字符，B中插入一个字符，A中修改一个字符
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1]);
            else
            {
                dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    string s = "intention";
    string t = "execution";
    cout << minDistance(s, t) << endl;
    return 0;
}