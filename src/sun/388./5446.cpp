#include <bits/stdc++.h>
using namespace std;
int minDifference(vector<int> &nums)
{
    int n= nums.size();
    if(n<5) return 0;
    int res = 0;
    sort(nums.begin(),nums.end());
    map<int,int> m;
    for(auto num:nums){
        m[num]++;
    }
    return res;

}
int main()
{
    //[5,3,2,4] ->0
    
    return 0;
}