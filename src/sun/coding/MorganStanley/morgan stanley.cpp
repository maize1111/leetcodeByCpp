#include <bits/stdc++.h>
using namespace std;

bool cmp(){

}
int main(){
    vector<string> strs = {"this","that","is","this","is","a"}; 
    unordered_map<string,int> m;
    for(auto s:strs){
        m[s]++;
    }

    unordered_map<string,int>::iterator it = m.begin();
    vector<pair<int,int>> new_s;
    

    priority_queue<string,vector<string>,cmp>;
}