#include <bits/stdc++.h>
using namespace std;
//dp[i][j] 是质量j的史莱姆分裂i次能够获得的最大收益
int main()
{
    int n, S;
    cin >> n >> S;

    if ((n - 1) * n / 2 < S)
    {
        cout << -1 << endl;
        return 0;
    }

    for(int i = 1;i<=n;i++){
        int sum = 0;
        int tmp = n;
        int p_i = n/(i+1);
        for(int j = 1;j<=i;j++){
            sum +=(p_i*(tmp-p_i));
            tmp -=p_i;
        }
        if(sum>=S){
            cout<<i<<endl;
            return 0;
        }

    }

    return 0;
}