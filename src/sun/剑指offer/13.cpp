#include <bits/stdc++.h>
using namespace std;
//机器人的运动范围
/*输入：m = 2, n = 3, k = 1
输出：3

*/
//深度优先搜索和广度有限搜索均可求解
int res = 0;
int diff[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool check(int i, int j, int m, int n, int k)
{
    //超出边界
    if (i < 0 || j < 0 || i >= m || j >= n)
    {
        return false;
    }
    if (i % 10 + i / 10 + j % 10 + j / 10 > k)
        return false;
    return true;
}
void dfs(int i, int j, vector<vector<int>> &visit, int m, int n, int k)
{
    if (check(i, j, m, n, k) == false)
        return;
    if (visit[i][j] == 1)
        return;
    visit[i][j] = 1;
    res++;
    for (int r = 0; r < 4; r++)
    {
        int x = i + diff[r][0], y = j + diff[r][1];
        dfs(x, y, visit, m, n, k);
    }
}
int movingCount(int m, int n, int k)
{
    vector<vector<int>> visit(m, vector<int>(n, 0));
    dfs(0, 0, visit, m, n, k);
    return res;
}

int main()
{
    int m = 2, n = 3, k = 1;
    cout << movingCount(m, n, k);
    return 0;
}