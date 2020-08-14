#include <iostream>
#include <vector>
using namespace std;

const int N = 12;
int n;
bool used[N];
int ret[N], cnt;
int count= 0;
//每层搜索需要记录上一层选择的数，用于判断绝对值不等于1的条件
//不使用vector存储路径,使用used记录使用过的数字即可
void dfs(int sz, int last)
{
    if (sz == n)
    {
        // for (int i = 0; i < cnt; i++)
        //     printf("%d ", ret[i]);
        // printf("\n");
        count++;
        return;
    }

    for (int i = 1; i <= n; i++)
        if (!used[i] && (last == -1 || abs(i - last) != 1))
        {
            used[i] = true;
            ret[cnt++] = i;
            dfs(sz + 1, i);
            used[i] = false;
            cnt--;
        }
}

int main()
{
    cin >> n;
    dfs(0, -1);
    cout<<count<<endl;
    return 0;
}