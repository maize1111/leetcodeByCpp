#include<bits/stdc++.h>
using namespace std;
// 最短距离，直线上选一点使得到给出的N个直线上的点的距离之和最短。 
//可以使用辅助数组
int main(){
    int N;
    cin>>N;
    vector<int> a(N);
    for(int i = 0;i<N;i++){
        cin>>a[i];
    } 
    sort(a.begin(),a.end());
    int num = a[(N-1)/2];
    long res = 0;
    for(int i = 0;i<N;i++){
        res += abs(a[i] - num);
    }
    cout<<res<<endl;
    return 0;
}