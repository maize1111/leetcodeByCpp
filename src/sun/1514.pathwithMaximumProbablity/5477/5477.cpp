#include <bits/stdc++.h>
using namespace std;
int minSwaps(vector<vector<int>> &grid)
{
    //统计每一行的最右边连续的0的个数
    int n = grid.size();
    vector<int> cnt(n, n);
    for (int i = 0; i < n; i++)
    {

        for (int j = n - 1; j >= 0; j--)
        {
            if (grid[i][j] == 1)
            {
                cnt[i] = n - j - 1;
                break;
            }
        }
    }
    //冒泡排序
    int count = 0;
    //最后一行不用判断
    for (int i = 0; i < n; i++)
    {
        int next = i + 1;
        while (cnt[i] < n - 1 - i)
        {
            count++;
            cnt[i] = cnt[next] + (cnt[next] = cnt[i]) * 0; // 交换
            if (cnt[i] < n - i - 1 && ++next >= n)
                return -1;
        }
    }
    return count;
}

int main()
{
    vector<vector<int>> grid={{0,0},{0,1}};
    int res = minSwaps(grid);
    cout<<res<<endl;
    return 0;
}