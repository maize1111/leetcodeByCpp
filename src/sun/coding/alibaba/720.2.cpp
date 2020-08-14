#include<bits/stdc++.h>
using namespace std;
//计算幸运数个数
// 给定一个正整数，计算相邻数之差的绝对值，最后计算得出一位数，为7则是幸运数。 
//题目给出l,r ,要求求出[l,r]内的幸运数的个数
//暴力肯定超时

bool isLuckNumber(int num){
    int res ;
    int n1;
    int n2;
    while(num/10>0){
        res = 0;
        while(num/10>0){
            n1 = num%10;
            num/=10;
            n2 = num%10;
            res = 10*res + abs(n1-n2);
        }
        num = res;
    }
    return num == 7?true:false;

}
int main(){
    int N;
    cin>>N;
    int l,r;
    int cnt;
    while(N--){
        cnt =0;
        cin>>l>>r;
        for(int i = l;i<=r;i++){
            if(isLuckNumber(i)){
                cnt++;
            }

        }
        cout<<cnt<<endl;
    }
    return 0;
}