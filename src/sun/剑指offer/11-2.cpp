#include <bits/stdc++.h>
using namespace std;
//寻找旋转排序数组中的最小值（可能有重复元素）（难度：困难）
/*输入: [2,2,2,0,1]
  输出: 0
*/
//上一题是此题目的特殊情况，只是没有重复元素时不会进入nums[mid]==nums[r]的分支。
int findMin(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    int mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (nums[mid] > nums[r])
        {
            l = mid + 1;
        }
        else if (nums[mid] < nums[r])
        {
            r = mid;
        }
        else
            r--;
    }
    return nums[l];
}
int main()
{
    vector<int> nums = {2, 2, 2, 0, 0, 1, 1};
    cout << findMin(nums);
    return 0;
}