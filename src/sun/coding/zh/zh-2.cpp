#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    if(n<k){
        cout<<-1<<endl;
        return 0;
    }
    if(k==1){
        cout<<"a"<<endl;
        return 0;
    }
    string res = "";
    for(int i = 0;i<n-k+2;i++){
        if(i%2){
            res += 'b';
        }
        else{
            res +='a';
        }
    }
    for(int i = 0;i<k-2;i++){
        res+=('c'+i);
    }
    cout<<res<<endl;

    return 0;
}