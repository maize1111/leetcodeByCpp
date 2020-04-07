#include <bits/stdc++.h>
using namespace std;
int minimumDeleteSum(string s1, string s2) {
        //最长公共子序列(删除字符的ASCII值的最小和)
        //动态规划
        //dp[i][j] :s1[1:i]和s2[1:j]的最大ascii值和的公共子串的ascii值和。
        //被删除的字符的ascii码值的和 = 原两个字符串的ascii码和 - 2×dp[m][n].
        int m = s1.size();
        int n = s2.size();
        int total = 0;
        for(auto c:s1){
            total += c;
        }
        for(auto c:s2){
            total += c;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j] = dp[i-1][j-1] +s2[j-1];
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return total-2*dp[m][n];

    }
int main()
{
    string s = "delete";
    string t = "leet";
    cout << minimumDeleteSum(s, t) << endl;
    return 0;
}