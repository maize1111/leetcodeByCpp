//leetcode 634 数组错排
#include <bits/stdc++.h>
using namespace std;
struct A{
    int x;
    int y;
    A(int u,int v):x(u),y(v){}
};
int main(){
    int mod = 1e9+7;
    int n ;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    vector<long long> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 0;
    for(int i = 2;i<=n;i++){
        dp[i] =  (((i - 1) * (dp[i - 2] + dp[i - 1])) % (10000000007));
    }
    cout<<dp[n]<<endl;
    vector<int> a(10,1);
    fill(a.begin(),a.end(),INT_MAX);

    vector<int>::iterator it = a.begin()+4;
    a.insert(it,7);
    cout<<a.size()<<endl;
   
    return 0;
}