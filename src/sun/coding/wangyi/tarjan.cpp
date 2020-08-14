#include <iostream>
#include <vector>
#include <stack>
using namespace std;
vector<int> v[100];
stack<int> stk;
int DFN[100],LOW[100];
int index;
bool vis[100];
void TarJan(int u)
{
    DFN[u]=LOW[u]=++index;
    stk.push(u);
    vis[u]=true;
    for(int w:v[u])
    {
        if(!DFN[w])
        {
            TarJan(w);
            LOW[u]=min(LOW[u],LOW[w]);
        }
        else if(vis[w]) LOW[u]=min(LOW[u],DFN[w]);
    }
    if(DFN[u]==LOW[u])
    {
        int s;
        do{
            s=stk.top();
            stk.pop();
            cout<<s<<" ";
            vis[s]=false;
        }while(u!=s);
        cout<<endl;
    }
} 
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;++i)
    {
        int s,e;
        cin>>s>>e;
        v[s].push_back(e);
    }
    for(int i=1;i<=n;++i)
    {
        if(!DFN[i]) TarJan(i);
    }
    return 0;
}