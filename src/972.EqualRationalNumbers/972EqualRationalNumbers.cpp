// 抄的！！！抄的！！！抄的！！！不会写！！！
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// 公约数函数
long long gcd(long long x, long long y)
{
    if (x > y)
    {
        return gcd(y, x);
    }
    if (x == 0 || y % x == 0)
    {
        return x;
    }
    return gcd(y % x, x);
}

// 化简分数 n/m
void simplify(long long &n, long long &m)
{
    if (n == 0 || m == 0)
    {
        n = 0;
        m = 1;
    }
    long long t = gcd(n, m);
    if (t > 0)
    {
        n /= t;
        m /= t;
    }
}

// 两分数相加 n1/d1 + n2/d2
// 分母相乘，分子互乘之后相加
// n1/d1 + n2/d2 = (n1*d2+n2*d1)/d1*d2
pair<long long, long long> add(long long n1, long long d1, long long n2, long long d2)
{
    long long n, d;
    if (d1 == 0)
    {
        n = n2;
        d = d2;
    }
    else if (d2 == 0)
    {
        n = n1;
        d = d1;
    }
    else
    {
        n = n1 * d2 + n2 * d1;
        d = d1 * d2;
    }

    simplify(n, d);
    return {n, d};
}

pair<int, int> trans(string s)
{
    long long int_part = 0;
    long long nonrep_part = 0;
    long long rep_part = 0;
    long long nonrep_len = 0;
    long long rep_len = 0;
    int i = 0, N = s.size();
    while (i < N && s[i] != '.')
    {
        int_part = int_part * 10 + s[i++] - '0';
    }
    ++i;
    while (i < N && s[i] != '(')
    {
        nonrep_part = nonrep_part * 10 + s[i++] - '0';
        ++nonrep_len;
    }
    ++i;
    while (i < N && s[i] != ')')
    {
        rep_part = rep_part * 10 + s[i++] - '0';
        ++rep_len;
    }

    long long p1 = pow(10, nonrep_len);
    long long p2 = pow(10, rep_len);
    long long p3 = p1 * p2;

    // 非重复小数部分的分子与分母
    long long nonrep_num = nonrep_part, nonrep_dom = p1;
    // 重复小数部分的分子与分母
    long long rep_num = rep_part * p2, rep_dom = p3 * (p2 - 1);

    simplify(nonrep_num, nonrep_dom);
    simplify(rep_num, rep_dom);
    auto p = add(nonrep_num, nonrep_dom, rep_num, rep_dom);
    return add(p.first, p.second, int_part, 1LL);
}

// 太难了吧，抄的答案
bool isRationalEqual(string S, string T)
{
    return trans(S) == trans(T);
}

// Test Function
int main()
{
    string S, T;
    while (cin >> S >> T)
    {
        cout << boolalpha << isRationalEqual(S, T) << endl;
    }

    return 0;
}
