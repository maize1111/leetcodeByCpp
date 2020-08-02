#include <bits/stdc++.h>
using namespace std;
//正则表达式匹配
//可以使用动态规划求解
//dp[i][j] 表示两个字符串的前i个和前j个的匹配情况
//需要考虑字符串为空串的情况
//各种匹配模式需要分析清楚
bool isMatch(string s, string p)
{
    int sn = s.size();
    int pn = p.size();
    vector<vector<bool>> dp(sn + 1, vector<bool>(pn + 1, false));

    dp[0][0] = true;

    for (int i = 1; i <= pn; i++)
    {
        if (p[i - 1] == '*' && dp[0][i - 2])
        {
            dp[0][i] = true;
        }
        else
        {
            dp[0][i] = false;
        }
    }
    if (sn >= 1)
    {
        for (int i = 1; i <= sn; i++)
        {
            dp[i][0] = false;
        }
    }
    for (int i = 1; i <= sn; i++)
    {
        for (int j = 1; j <= pn; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                if (s[i - 1] != p[j - 2] && p[j - 2] != '.')
                    dp[i][j] = dp[i][j - 2];
                else
                {
                    dp[i][j] = dp[i][j - 1] || dp[i][j - 2] || dp[i - 1][j];
                }
            }
        }
    }
    return dp[sn][pn];
}
int main()
{

    string s = "aab";
    string p = "c*a*b";
    cout<<isMatch(s,p);
    return 0;
}