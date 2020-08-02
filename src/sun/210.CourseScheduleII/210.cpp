#include <bits/stdc++.h>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int> > &prerequisites)
{
    vector<int> res;
    //统计入度，建立邻接表
    vector<int> inDegree(numCourses, 0);
    vector<vector<int> > graph(numCourses, vector<int>()); //构建临接表（用vector储存临接点，方便访问）
    for (auto p:prerequisites)
    {
        inDegree[p[0]++];
        graph[p[1]].push_back(p[0]);
    }
    //将入度为0的节点入队
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
    {
        if (inDegree[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        for (int i = 0; i < graph[cur].size(); i++)
        {
            inDegree[graph[cur][i]]--;
            if (inDegree[graph[cur][i]] == 0)
            {
                q.push(graph[cur][i]);
            }
        }
        cout << q.size() << endl;
    }
    return res.size() == numCourses ? res : vector<int>();
}
int main()
{
    int nums = 2;
    vector<vector<int> > prerequisites = {{1,0}};
    vector<int> a(10,0);

    return 0;
}