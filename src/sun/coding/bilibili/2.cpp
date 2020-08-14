#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
    string sa = to_string(a);
    string sb = to_string(b);
    return (sa+sb) <(sb+sa);
}

int main(){
    string s;
    while(cin>>s){
        vector<int>nums;
        char *str = (char *)s.c_str();//string --> char
        const char *split = ",";
        char *p = strtok (str,split);//逗号分隔依次取出
        int a;
        while(p != NULL) {
            sscanf(p, "%d", &a);//char ---> int
            nums.push_back(a);
            p = strtok(NULL,split);
        }
        sort(nums.begin(),nums.end(),cmp);
        string res = "";
        for(int i = 0;i<nums.size();i++){
            res+= to_string(nums[i]);
        }
        cout<<res<<endl;

    }
    return 0;
}