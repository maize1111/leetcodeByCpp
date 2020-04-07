#include <bits/stdc++.h>
using namespace std;
int longestCommonSubsequence(string text1, string text2)
{
    //最长公共子序列可以不连续
    int m = text1.size();
    int n = text2.size();
    if (n * m == 0)
        return 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (text1[i - 1] == text2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[m][n];
}
int main()
{
    string s = "abc";
    string t = "def";
    cout << longestCommonSubsequence(s, t) << endl;
    return 0;
}