#include <bits/stdc++.h>
using namespace std;
//https://blog.csdn.net/DebugMyself/article/details/107939822
//学术认可
// 对于输入案例：
// 5
// 6
// 1    3
// 2    1
// 3    2
// 3    5
// 4    5
// 5    4
// 则输出应为4，因为教授1与教授2互相认可，教授1与教授3互相认可，教授2与教授3互相认可，教授4与教授5互相认可。因此共有4对教授是互相认可的。
//使用邻接表求解会超时
//使用tarjan计算强连通
struct edge{
    int u;
    int v;
    edge(int x, int y) {
       u = x;
       v = y; 
    }
};
stack<int> stk;
vector<int> DFN,LOW;
vector<bool> vis;
vector<vector<edge>> graph;
vector<vector<int>> result;
int cnt = 0;

void tarjan(int cur){
    
    DFN[cur]=LOW[cur]=cnt++;
    vis[cur] = true;
    stk.push(cur);
    int next = cur ;
    for (int i = 0; i < graph[cur].size(); i++) {
        next = graph[cur][i].v;
        if (DFN[next] == -1){
            tarjan(next);
            LOW[cur] = min(LOW[cur], LOW[next]);
        }else if (vis[next]){
            LOW[cur] = min(LOW[cur], LOW[next]);
        }
    }
    if (DFN[cur] == LOW[cur]){
        vector<int> temp ;
        while(cur != next){
            next = stk.top();
            stk.pop();
            temp.push_back(next);
            vis[next] = false;
        }
        result.push_back(temp);
    }
    return;
}
int main(){
    int m,n;
    cin>>n>>m;
    DFN = vector<int>(n,-1);
    LOW = vector<int>(n,-1);
    vis = vector<bool>(n,false);
    graph = vector<vector<edge>>(n,vector<edge>());
    for(int i = 0; i < m;i++){
        int u,v;
        cin>>u>>v;
        u--;
        v--;
        graph[u].push_back(edge(u,v));
    }
    tarjan(1);
    int res = 0;
    for(auto list:result){
        int num = list.size();
        res += (num-1)*num/2;
    }
    cout<<res<<endl;
    return 0;
}

