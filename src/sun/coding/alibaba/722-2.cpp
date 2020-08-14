// 长度为 n 的数组，数组中每个元素 a 满足：1<=a<=n
// 求连续区间的数量，要求区间中相同元素的数量 >=m
// 例如：
// 5 2
// 1 2 1 5 2
// 4
// 可以有4种可能：[1,3]，[1,5]，[2,5]，[1,4]
// 解题思路：使用双指针，时间复杂度O(n)
// 如果[l,r]满足条件，则[k,r]也满足条件（1<=k<=l）
// 对于每一个r，找到满足条件最大的l，这样能做到不重不漏
// r向右扩张时，当前区间仍然满足条件
// pos[i]记录值为i的数字出现过得位置，用于更新l
#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10;

int n, m;
int a[N];
vector<int> pos[N];

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int ret = 0, l = 0, r = 1;

    while (r <= n)
    {
        int c = a[r];
        pos[c].push_back(r++);

        int t = pos[c].size();
        if (t >= m)
            l = max(l, pos[c][t - m]);

        ret += l;
    }

    cout << ret;

    return 0;
}
