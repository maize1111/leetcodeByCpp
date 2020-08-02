#include <bits/stdc++.h>
using namespace std;
int rangeSum(vector<int> &nums, int n, int left, int right)
{
    vector<int> sum;
    int pre = 0;
    for(int i = 0;i<nums.size();i++){
        int pre = nums[i];
        sum.push_back(pre);
        for(int j = i+1;j<nums.size();j++){
            pre+=nums[j];
            sum.push_back(pre);
        }
    }
    sort(sum.begin(),sum.end());
    int res = 0;
    for(int i = left-1;i<right;i++){
        res+=sum[i];
    }
    return res;
}
int main()
{
    //1, 3, 6, 10, 2, 5, 9, 3, 7, 4 
    //nums = [1,2,3,4], n = 4, left = 1, right = 5
    vector<int> nums = {1, 2, 3, 4};
    int n = 4;
    int left = 1, right = 5;
    cout << rangeSum(nums, n, left, right);
    return 0;
}