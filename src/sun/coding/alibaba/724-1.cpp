#include<bits/stdc++.h>
using namespace std;
// 吃烧饼大赛。有n个盘子，每个盘子内有s[i]个烧饼。每次选取一个 x（1≤x≤n），可以吃到1 ～ x 号盘子里的一个烧饼。若这1～x个盘子中有空盘时无法进行该操作。
// 假设小明的食量是无限大，最多可以吃掉多少烧饼。
//使用long long 因为数据范围大，使用动态规划思想，但是不需要使用vector存储
//对每个盘子，最多可吃的数量为：它和它前面的盘子中最少的烧饼数。
//1 2 3
//3
//2 1 3
//4
int main(){
    int n;
    cin>>n;
    vector<int> nums(n,0);
    int min_num = INT_MAX;
    long long ans = 0;
    for(int i = 0; i < n; i++){
        scanf("%d",&nums[i]);
        if (nums[i] < min_num){
            min_num = nums[i];
        }
        ans += min_num;
    }
    cout << ans << endl;
    return 0;
}