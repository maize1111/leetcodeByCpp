#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    // 暴力算法O(n), 二分法O(log n)
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (nums[mid] == target)
            return mid;
        else if (nums[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
