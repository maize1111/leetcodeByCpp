#include <bits/stdc++.h>
using namespace std;
int maxCoins(vector<int> &nums)
{
    //分治算法 动态规划
    //dp[i][j] 表示开区间(i,j) 能获得的金币的最大值
    //设k为(i,j)中最后被戳爆的气球编号，其左右能获得的最大值相互不受影响
    //动态转移方程:dp[i][j] = dp[i][k]+dp[k][j] + nums[i]*nums[k]*nums[j]
    //由开区间长度为3开始计算，这样大区间计算时，所有子区间的结果都已经获得
    //为了方便求解，需要假设nums[-1] = nums[n] = 1
    int n = nums.size();
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int len = 3; len <= n + 2; len++)
    {
        for (int i = 0; i < n+3-len; i++)
        {
            int j = i + len - 1;
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = max(dp[i][j], (dp[i][k] + dp[k][j] + nums[i] * nums[k] * nums[j]));
            }
        }
    }
    return dp[0][n + 1];
}

int main()
{

    vector<int> nums = {3, 1, 5, 8};
    int res = maxCoins(nums);
    cout<<res<<endl;
    return 0;
}