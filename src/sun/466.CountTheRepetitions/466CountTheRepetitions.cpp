#include <bits/stdc++.h>
using namespace std;

int getMaxRepetitions(string s1, int n1, string s2, int n2)
{
    vector<int> pre(s1.length(), 0);
    vector<int> cnt(s1.length(), 0);
    int ind = 0, d2 = 0;
    int c1 = 0, c2 = 0;
    int ans;
    while (1)
    {
        c1++;
        if (c1 > n1)
        {
            return c2 / n2;
        }
        ans = -1;
        int flag = 1;
        for (int i = 0; i < s1.length(); i++)
        {
            if (s1[i] == s2[d2])
            {
                flag = 0;
                d2++;
                if (d2 >= s2.length())
                {
                    c2++;
                    if (pre[i] != 0)
                    {
                        ind = i;
                        int rst = n1 - c1;
                        int a1 = (c1 - pre[i]);
                        int a2 = (c2 - cnt[i]);
                        c1 += rst / a1 * a1;
                        c2 += rst / a1 * a2;
                    }
                    else
                    {
                        pre[i] = c1;
                        cnt[i] = c2;
                    }
                    d2 = 0;
                }
            }
        }

        if (flag)
        {
            return 0;
        }
    }
}
int main()
{
    int n1 = 100, n2 = 2;
    string s1 = "abacb", s2 = "bcaa";
    cout<<getMaxRepetitions(s1,n1,s2,n2);
    vector<int> a = {1,2,4};
    return 0;
}