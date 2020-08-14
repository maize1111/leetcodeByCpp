#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin,str); 
    reverse(str.begin(),str.end());
    int i = 0,j= 0;
    while(j<str.size()){
        while(j<str.size()&&str[j]!=' '){
            j++;
        }
        reverse(str.begin()+i,str.begin()+j);
        j++;
        i = j;
    }
    cout<<str<<endl;
    return 0;
}
