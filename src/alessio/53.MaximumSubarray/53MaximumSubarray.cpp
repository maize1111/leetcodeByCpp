#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int> &nums)
{
    int cur = nums[0], maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        cur = max(nums[i], cur + nums[i]);
        maxSum = max(maxSum, cur);
    }
    return maxSum;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
