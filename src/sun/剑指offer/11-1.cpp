#include <bits/stdc++.h>
using namespace std;
//寻找旋转排序数组中的最小值（无重复元素）（难度：中等）
/*输入: [3,4,5,1,2]
  输出: 1
*/
int findMin(vector<int> &nums)
{
    int l = 0;
    int r = nums.size() - 1;
    //未发生旋转
    if (nums[l] <= nums[r])
        return nums[l];
    int mid;
    //左闭右闭，结束循环条件l=r+1
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        //找到最小值
        if (mid - 1 >= 0 && nums[mid] < nums[mid - 1])
        {
            return nums[mid];
        }
        if (mid + 1 < nums.size() && nums[mid] > nums[mid + 1])
        {
            return nums[mid + 1];
        }
        //未找到 更新左右边界
        if (nums[mid] < nums[r])
        {
            r = mid - 1;
        }
        else if (nums[mid] > nums[l])
        {
            l = mid + 1;
        }
    }

    return -1;
}
int main()
{
    vector<int> nums = {3, 5, 6, 7, 0, 1, 2};
    cout << findMin(nums);
    return 0;
}