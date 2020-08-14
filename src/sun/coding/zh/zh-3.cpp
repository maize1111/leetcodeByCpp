#include <bits/stdc++.h>
using namespace std;
//dp[i][j] 是质量j的史莱姆分裂i次能够获得的最大收益
int main()
{
    int n, S;
    cin >> n >> S;

    if ((n - 1) * n / 2 < S)
    {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            if (i == 1)
            {
                //分裂一次直接二分即可
                dp[i][j] = (j - j / 2) * j / 2;
            }
            else
            {
                for (int k = 1; k < j; k++)
                {
                    dp[i][j] = max(dp[i - 1][k] + k * (j - k), dp[i][j]);
                }
            }
            if (dp[i][j] >= S)
            {
                cout << i << endl;
                return 0;
            }
        }
    }

    return 0;
}