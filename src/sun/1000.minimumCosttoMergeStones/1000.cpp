#include <bits/stdc++.h>
using namespace std;
int mergeStones(vector<int> &stones, int K)
{
    //动态规划
    //首先判断是否能合成一堆
    int n = stones.size();
    if ((n - 1) % (K - 1))
    {
        return -1;
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> prefix(n+1,0);
    for (int i = 1; i<=n; i++)
    {
        prefix[i] = stones[i-1]+prefix[i - 1];
    }

    //使用prefix[i] 存储[0,i-1]的石头总数，为了方便后续计算[i,j]的石头总数

    //dp[i][j] 表示[i,j]的最小成本
    //m：每次合并的区间长度，从K到N。m<K时已经初始化为0，所以不用遍历。
    //dp[i][i+m-1] = min(dp[i][k] + dp[k+1][i+m-1] for k in range(i, i+m-1, K-1)) + (prefix[i+m] - prefix[i] if (m-1)%(K-1) == 0 else 0)
    //结果 dp[0][n-1]
    for(int m = K;m<n+1;m++){
        for(int i = 0;i<n-m+1;i++){
            int j = i+m-1;
            dp[i][j] = INT_MAX;
            for(int k = i;k<j;k+=(K-1)){
                dp[i][j] = min(dp[i][j],(dp[i][k]+dp[k+1][j]));
            }
            if((m-1)%(K-1) == 0){
                dp[i][j]+=prefix[i+m]-prefix[i];
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    vector<int> stones = {3, 5, 1, 2, 6};
    int K = 3;
    int res = mergeStones(stones,K);
    cout<<res<<endl;

    return 0;
}
