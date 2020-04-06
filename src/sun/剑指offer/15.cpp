#include <bits/stdc++.h>
using namespace std;
//二进制中1的个数，汉明重量
/*
输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
*/

//位运算
int hammingWeight(uint32_t n)
{
    int cnt = 0;
    while (n > 0)
    {
        cnt += n & 1;
        n >>= 1;
    }
    return cnt;
}
int main()
{
    uint32_t n = 10001000000000000000000000001011;
    cout << hammingWeight(n);
    return 0;
}