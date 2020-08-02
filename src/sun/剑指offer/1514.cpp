#include <bits/stdc++.h>
using namespace std;
double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start, int end)
{
    //bfs
    if (n == 0)
    {
        return 0;
    }
    //构造邻接表
    vector<vector<int>> G(n, vector<int>());
    for (auto e : edges)
    {
        G[e[0]].push_back(e[1]);
        G[e[1]].push_back(e[0]);
    }
    //初始化队列
    vector<double> probs(n, 0);
    queue<int> Q;
    //初始化概率
    probs[start] = 1;
    Q.push(start);
    //bfs
    // while (!Q.empty())
    // {
    //     int qsize = Q.size();
    //     set<int> s;

    //     while (qsize--)
    //     {
    //         int v = Q.front();
    //         Q.pop();
    //         if (v == end)
    //         {
    //             continue;
    //         }

    //         for (auto ew : G[v])
    //         {
    //             double nextProb = probs[v] * succProb[ew[0]];
    //             if (nextProb > probs[ew[1]])
    //             {
    //                 probs[ew[1]] = nextProb;
    //                 s.insert(ew[1]);
    //             }
    //         }
    //     }
    //     for (int w : s)
    //     {
    //         Q.push(w);
    //     }
    // }
    return probs[end];
}
int main()
{
    int n = 3;
    vector<vector<int>> edges ={{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};
    int start = 0;
    int end = 2;
    maxProbability(n,edges,succProb,start,end);

    return 0;
}