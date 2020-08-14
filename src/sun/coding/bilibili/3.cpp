#include <bits/stdc++.h>
using namespace std;
// 0-1 背包问题
// 5
// 10
// 2 2 6 5 4
// 6 3 5 4 6

// 15
int main(){
    int M,N;
    cin>>M>>N;
    vector<int> w(M,0);
    vector<int> v(M,0);
    for(int i = 0;i<M;i++){
        cin>>w[i];
    }
    for(int i = 0;i<M;i++){
        cin>>v[i];
    }
    //dp[i][j] 表示背包容量为j时，前i件物品的最大价值
    vector<vector<int>>dp(M+1,vector<int>(N+1,0));
    for(int i = 1;i<=M;i++){
        for(int j = 1;j<=N;j++){
            if(j<w[i-1]){
                dp[i][j] = dp[i-1][j];
            }
            else{
                int tmp1 = dp[i-1][j-w[i-1]]+v[i-1];
                int tmp2 = dp[i-1][j];
                dp[i][j] = max(tmp1,tmp2);
            }
        }
        
    }
    cout<<dp[M][N]<<endl;
    return 0;
}