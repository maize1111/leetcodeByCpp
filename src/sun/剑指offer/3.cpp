#include <bits/stdc++.h>
using namespace std;
//数组中的重复数字
//input :[2, 3, 1, 0, 2, 5, 3]
//output:2 or 3
int findRepeatNumber(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int i = 0;
    while(i<nums.size()-1){
        if(nums[i]==nums[i+1]){
            return nums[i];
        }
        i++;
    }
    return -1;

}
int main(){
    vector<int> nums= {2, 3, 1, 0, 2, 5, 3};
    cout<<findRepeatNumber(nums);
    return 0;
}