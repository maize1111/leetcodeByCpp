#include <bits/stdc++.h>
using namespace std;
//剪绳子
/*
输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1
输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36
*/
//贪心算法：尽量剪长度为三的段，如果最后一段为4的话剪为2+2
//由于2<=n<=1000 结果可能非常大，需要取模，另外使用动态规划时间复杂度比较高，考虑使用贪心算法
int pow3(int times){
        long long res = 3;
        int cnt = 1;
        while(cnt*2<times){
            res = (res%1000000007)*(res%1000000007);
            cnt*=2;
        }
        while(cnt<times){
            res = (res*3)%1000000007;
            cnt++;
        }
        return res;
    }
    int cuttingRope(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        if(n==4) return 4;
        long long res;
        if(n%3==1){
            res = pow3(n/3-1)%1000000007;
            res = res*4%1000000007;
        }
        else if(n%3==0){
            res= pow3(n/3)%1000000007;
        }
        else{
            res =  pow3(n/3)%1000000007;
            res = res*2%1000000007;
        }
            
        return res;
        
    }
int main()
{
    int n = 9;
    cout << cuttingRope(n);
    return 0;
}