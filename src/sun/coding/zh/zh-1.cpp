#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin>>N;
    int num = 0;
    unordered_map<int,string> m;
    m[0] = "0000";
    m[1] = "0001";
    m[2] = "0010";
    m[3] = "0011";
    m[4] = "0100";
    m[5] = "0101";
    m[6] = "0110";
    m[7] = "0111";
    m[8] = "1000";
    m[9] = "1001";
    while(N--){
        cin>>num;
        //拆分处理
        string res = "";
        for(int i = 0;i<3;i++){
            res = m[num%10] + res;
            num/=10;
        }
        reverse(res.begin(),res.end());
        int index = 0;
        while(index<res.size()){
            if(res[index]=='1'){
                break;
            }
            index++;
        }
        if(res[0] == '1'){
            cout<<res<<endl;
        }
        else{
            cout<<res.substr(index,res.size()-index)<<endl;
        }

    }
    return 0;
}