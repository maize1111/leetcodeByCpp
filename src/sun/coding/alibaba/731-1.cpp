#include <bits/stdc++.h>
using namespace std;

//res = c(n,i)*pow(m.i) i在[0,n]
int main()
{
    int mod = 1e9 + 7;
    int n = 3;
    int m = 2;
    int res = 0;
    int c2 = 1;
    int c1 = 1;
    for (int i = 0; i < n; i++)
    {
        res += (c1 * c2) % mod;
        c1 *= (n - i) / (i + 1);
        c2 *= m;
    }
    res += c2;
    return 0;
}