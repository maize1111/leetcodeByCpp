#include<bits/stdc++.h>
using namespace std;
//找出M<=N,M的二进制位数和N的二进制位数一样，且M的二进制中所包含的1的个数最多中的最小的M
//6->5
//13->11
//7->7
//思路：获取最高数位1，剩下
int len(int n){
    int l = 0;
    while(n){
        l++;
        n >>= 1;
    }
    return l;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int n ;
        cin>>n;
        int l = len(n);
        if(n == ((1<<l)-1)){
            cout<<n<<endl;
            continue;
        }
        int a = 1<<(l-1);
        int b = n-a;
        int l2 = len(b);
        b = (1<<l2-1)-1;
        int res = a|b;
        cout<<res<<endl;
    }
    return 0;
}