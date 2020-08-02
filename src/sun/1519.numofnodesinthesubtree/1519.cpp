#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<bool> vis;
vector<int> ans;
void dfs(int in, vector<int> &a, string &labels)
{
    //跳过已访问节点
    if (vis[in])
    {
        return;
    }
    //标记节点
    vis[in] = true;
    vector<int> tmp(26);
    for (auto &out : graph[in])
    {
        dfs(out, tmp, labels);
    }
    ans[in] = ++tmp[labels[in] - 'a'];
    //更新子树所有节点中字母出现的次数
    for (int i = 0; i < 26; ++i)
    {
        a[i] += tmp[i];
    }
}
vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
{
    graph.resize(labels.size());
    vis.resize(labels.size(), false);
    ans.resize(labels.size());
    //建立邻接表
    for (auto &e : edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    //记录子树中字母出现次数
    vector<int> tmp(26);
    //dfs深度优先搜索
    dfs(0, tmp, labels);
    return ans;
}


int main()
{
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    string labels = "abaedcd";

    vector<int> res = countSubTrees(n, edges, labels);
    cout<<res.size()<<endl;

    return 0;
}

// 输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels = "abaedcd"
// 输出：[2,1,1,1,1,1,1]