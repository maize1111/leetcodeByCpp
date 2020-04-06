#include <bits/stdc++.h>
using namespace std;
int maxUncrossedLines(vector<int> &A, vector<int> &B)
{
    //即求最长公共子序列长度
    int m = A.size();
    int n = B.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}
int main()
{
    vector<int> A = {1, 3, 7, 1, 7, 5};
    vector<int> B = {1, 9, 2, 5, 1};
    cout << maxUncrossedLines(A, B) << endl;
    return 0;
}