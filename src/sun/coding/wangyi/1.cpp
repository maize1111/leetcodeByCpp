#include <bits/stdc++.h>
using namespace std;
//输入一个包含n个正整数的数组a,可以将数组中的每个数分拆成若干个和为a[i]的正整数，分拆后这个数组最多能有多少个素数
// 输入：
// 3
// 5 3 7
// 输出：
// 6
int main(){
    int n ;
    cin>>n;
    long ans = 0;
    int a;
    for(int i = 0;i<n;i++){
        cin>>a;
        ans += (a>>1);
    }
    cout<<ans<<endl;
    return 0;
}