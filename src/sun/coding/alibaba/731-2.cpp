#include <bits/stdc++.h>
using namespace std;
int diff[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
struct node
{
    int x, y, cost;
    char type;
    node(int a, int b, int c, char d) : x(a), y(b), cost(c), type(d) {}
};
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<char>> grid(n, vector<char>(m));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    while (q--)
    {
        //存放每个点的最小支出
        vector<vector<int>> visit(n, vector<int>(m, INT_MAX));
        vector<int> query(4, 0);
        for (int i = 0; i < 4; i++)
        {
            cin >> query[i];
        }
        visit[query[0] - 1][query[1] - 1] = 0;
        queue<node> que;
        que.push(node(query[0] - 1, query[1] - 1, 0, grid[query[0] - 1][query[1] - 1]));
        int res = INT_MAX;
        while (!que.empty())
        {
            int sz = que.size();
            while (sz--)
            {
                auto tmp = que.front();
                que.pop();
                if (tmp.x == query[2] - 1 && tmp.y == query[3] - 1)
                {
                    res = min(res, tmp.cost);
                    continue;
                }

                for (int k = 0; k < 4; k++)
                {
                    int x = tmp.x + diff[k][0];
                    int y = tmp.y + diff[k][1];
                    if (x >= n || x < 0 || y < 0 || y >= m)
                    {
                        continue;
                    }
                    int cost = 0;
                    if (tmp.type != grid[x][y])
                    {
                        cost = 5;
                    }
                    else if (grid[x][y] == 'c')
                    {
                        cost = 3;
                    }
                    else
                    {
                        cost = 2;
                    }
                    if (visit[x][y] > tmp.cost + cost)
                    {
                        visit[x][y] = tmp.cost + cost;
                        que.push(node(x, y, visit[x][y], grid[x][y]));
                    }
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}