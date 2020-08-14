#include <bits/stdc++.h>
using namespace std;
//https://blog.csdn.net/DebugMyself/article/details/107909095
//平分物品
//使用dfs可以暴力求解
//每个物品都有三种状态，给第一个人、给第二个人、丢弃
// 输入：
// 1
// 5
// 30    60    5    15    30
// 输出应为：
// 20
int res = INT_MAX;
void dfs(vector<int>& a,int index,int drop,int s1,int s2){
    if(index == a.size()){
        if(s1 == s2)
            res = min(res,drop);
        return;
    }
    dfs(a,index+1,drop,s1+a[index],s2);
    dfs(a,index+1,drop,s1,s2+a[index]);
    dfs(a,index+1,drop+a[index],s1,s2);
}
int main(){
    int T;
    cin>>T;
    while(T--){
        int n ;
        cin>>n;
        res = INT_MAX;
        vector<int> a(n,0);
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        dfs(a,0,0,0,0);
        cout<<res<<endl;
    }
    
    return 0;
}