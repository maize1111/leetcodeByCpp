#include <bits/stdc++.h>
using namespace std;
//数值的整数次方
/*
输入: 2.00000, 10
输出: 1024.00000
输入: 2.10000, 3
输出: 9.26100
输入: 2.00000, -2
输出: 0.25000
解释: 2-2 = 1/22 = 1/4 = 0.25


*/
double myPow(double x, int n)
{
    double res = 1.0;
    for (int i = n; i!=0; i /= 2)
    {
        if (i % 2 != 0)
        {
            res *= x;
        }
        x *= x;
    }
    if(n<0){
        return 1/res;
    }
    return res;
}
int main()
{
    double x = 2.0;
    int n = -9;
    cout << myPow(x, n);
    return 0;
}