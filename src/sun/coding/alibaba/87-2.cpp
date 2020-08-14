//https://blog.csdn.net/johsnows/article/details/107897535
//ac自动机
#include <iostream>
#include <stdio.h>
#include <cstring>
#define ps push_back
using namespace std;
const int maxn=2e5+5;
int fail[maxn];
int node[maxn][27];
int val[maxn];
int que[maxn];
int cnt, root;
char s[maxn], sub[maxn];
char ans[maxn];
int top;
int d[maxn];
void insert(char s[])
{
    int now=root;
    for(int i=0; s[i]; i++)
    {
        int pos=s[i]-'a';
        if(node[now][pos])now=node[now][pos];
        else node[now][pos]=++cnt, now=node[now][pos];
    }
    val[now]=strlen(s);
}
void build()
{
    int head=0, tail=0;
    que[tail++]=root;
//    for(int i=0; i<26; i++)if(node[root][i])que[tail++]=node[root][i];
    while(head<tail){
        int now=que[head];
        for(int i=0; i<26; i++)
        {
            int u=node[now][i], v=fail[now];
            if(u==0)node[now][i]=node[v][i];
            else{
                que[tail++]=u;
//                while(v && !node[v][i])v=fail[v];          //找fail节点的i个字母是否存在，存在则能匹配
                if(now!=root)fail[u]=node[v][i];    // 不能让fail指向自己，now=root得情况会让fail[u]=u
            }
        }
        head++;
    }
    return;
}
int main()
{
    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);
//    freopen("censor_gold//2.in", "r", stdin);
//    freopen("censor_gold//my2.out", "w", stdout);
    cin>>s;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>sub;
        insert(sub);
    }
    build();
    int now=root;
    for(int i=0; s[i]; i++)
    {
        d[++top]=now=node[now][s[i]-'a'];
        ans[top]=s[i];
        if(val[now])
        {
            top-=val[now];
            now=d[top];
        }
    }
    for(int i=1; i<=top; i++)printf("%c", ans[i]);
    return 0;
}
/***
sdqaaaq
2
qq
aaa
**/
 