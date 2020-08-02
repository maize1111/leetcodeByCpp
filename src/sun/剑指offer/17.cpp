#include <bits/stdc++.h>
using namespace std;
//大数问题,需要考虑超出int范围时转换为字符串打印
//另外需要考虑n<=0的输出
//leetcode对此题目进行了一定的简化
vector<int> printNumbers(int n)
{
    vector<int> res;
    if (n <= 0)
        return {};
    for (int i = 1; i < pow(10, n); i++)
    {
        res.push_back(i);
    }
    return res;
}
int main()
{
    vector<int> res = printNumbers(6);
    return 0;
}
//考虑使用递归进行输出，字符串的每一个位置上存在的可能都是‘0’ - ‘9’
//打印时注意不输出前导0