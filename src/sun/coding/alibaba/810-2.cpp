#include<bits/stdc++.h>
using namespace std;
// 小明和小强都往上爬，第一个到达终点的胜利。 
//求二叉树中谁的深度更小
//使用深度优先搜索

#include <bits/stdc++.h>
using namespace std; 
const int MAXN = 1e5 + 10; 
int n, m; 
vector<int> v[MAXN]; 
int dep[MAXN]; 
void dfs(int x) {
    for (auto y : v[x]) 
    { 
        dep[y] = dep[x] + 1;
        dfs(y);
    }
} 
int main() 
{ 
    scanf("%d%d", &n, &m);
    for (int i = 2;i <= n; i++) { 
        int x; 
        scanf("%d", &x); 
         v[x].push_back(i);
    } 
    dfs(1); 
    for (int i = 1; i <= m; i++) 
    { 
        int x, y; scanf("%d%d", &x, &y);
        if (dep[x] <= dep[y]) 
            printf("A\n");
        else 
            printf("B\n");
    }
}