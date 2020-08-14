#include <bits/stdc++.h>
using namespace std;
//https://blog.csdn.net/DebugMyself/article/details/107894768
//买票问题
//动态规划
int main(){
    int n ;
    cin>>n;
    vector<int> a(n,0);
    vector<int> b(n-1,0);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    for(int i = 0;i<n-1;i++){
        cin>>b[i];
    }

    //dp[i]表示到i买票所用的最短时间
    vector<int> dp(n,INT_MAX);
    dp[0] = a[0];
    dp[1] = min(a[0]+a[1], b[0]);
    for(int i = 2;i<n;i++){
        dp[i] = min(dp[i-1]+a[i],dp[i-2]+b[i-1]);
    }
    //dp[n-1]为所需要花的秒数，将其转换成小时加到8:00即可
    cout<<dp[n-1]<<endl;
    return 0;
}