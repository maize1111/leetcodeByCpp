#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int m;
int n;
int bfs(vector<vector<int>> &forest, int source, int target)
{
    queue<int> q{{source}};
    vector<int> visited(m * n);
    visited[source] = 1;
    int steps = 0;
    while (!q.empty())
    {
        int k = q.size();
        while (k--)
        {
            int cur = q.front();
            q.pop();
            if (cur == target)
                return steps;
            for (int i = 0; i < 4; i++)
            {
                int nx = cur / n + dx[i];
                int ny = cur % n + dy[i];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || forest[nx][ny] == 0 || visited[nx * n + ny])
                    continue;
                q.push(nx * n + ny);
                visited[nx * n + ny] = 1;
            }
        }
        steps++;
    }
    return -1;
}
int cutOffTree(vector<vector<int>> &forest)
{
    m = forest.size();
    n = forest[0].size();
    //第一维为高度，第二维为坐标
    vector<pair<int, int>> v;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (forest[i][j] > 1)
            {
                v.push_back({forest[i][j], i * n + j});
            }
        }
    }
    sort(v.begin(), v.end());
    int ans = bfs(forest, 0, v[0].second);
    if (ans == -1)
        return -1;
    for (int i = 0; i < v.size() - 1; i++)
    {
        int temp = bfs(forest, v[i].second, v[i + 1].second);
        if (temp == -1)
            return -1;
        ans += temp;
    }
    return ans;
}

int main()
{
    vector<vector<int>> forest ={{1,2,0},{5,3,4},{6,8,7}};
        // {{0, 0, 0, 3528, 2256, 9394, 3153},
        //  {8740, 1758, 6319, 3400, 4502, 7475, 6812},
        //  {0, 0, 3079, 6312, 0, 0, 0},
        //  {6828, 0, 0, 0, 0, 0, 8145},
        //  {6964, 4631, 0, 0, 0, 4811, 0},
        //  {0, 0, 0, 0, 9734, 4696, 4246},
        //  {3413, 8887, 0, 4766, 0, 0, 0},
        //  {7739, 0, 0, 2920, 0, 5321, 2250},
        //  {3032, 0, 3015, 0, 3269, 8582, 0}};
    int res = cutOffTree(forest);
    cout << res << endl;
    return 0;
}