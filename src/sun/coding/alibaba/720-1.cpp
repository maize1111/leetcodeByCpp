#include <bits/stdc++.h>
using namespace std;
//输入n，k，问是否存在x,y,z使得x+y+z = n并且gcd(x,y)=k,gcd(z,y)=k,gcd(x,z)=k
//如果存在输出任意一组满足条件的答案x y z否则输出-1
int main()
{
    //暴力必然超时
    int n, k;
    cin >> n >> k;
    if (n % k != 0)
    {
        cout << -1 << endl;
        return 0;
    }
    int num = n / k;
    //将num分成互质的三个数之和即可，分不成则输出-1；
    for (int x = 1; x <= num - 3; x++)
    {
        for (int y = x + 1; y < num - x; y++)
        {
            int z = num - x - y;
            if (x != y && y != z && __gcd(x, y) == 1 && __gcd(x, z) == 1 && __gcd(y, z) == 1)
            {
                cout<<k*x<<" "<<k*y<<" "<<k*z<<endl;
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}