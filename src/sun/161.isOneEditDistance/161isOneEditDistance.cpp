#include <bits/stdc++.h>
using namespace std;
//s比t短1
bool insertcheck(string s, string t)
{
    int i = 0, j = 0;
    while (s[i] == t[j])
    {
        i++;
        j++;
    }
    return s.substr(i, s.size()) == t.substr(j+1, t.size() - j-1);
}
bool replacecheck(string s, string t)
{
    if(s==t) return false;
    int i = 0, j = 0;
    while (s[i] == t[j])
    {
        i++;
        j++;
    }
    return s.substr(i + 1, s.size() - i - 1) == t.substr(j + 1, t.size() - j - 1);
}

bool isOneEditDistance(string s, string t)
{
    if (s.size() == t.size())
    {
        return replacecheck(s, t);
    }
    else if (s.size() == t.size() - 1)
    {
        return insertcheck(s, t);
    }
    else if (s.size() == t.size() + 1)
    {
        return insertcheck(t, s);
    }
    else
        return false;
}
int main()
{
    string s = "ab";
    string t = "acc";
    cout<<isOneEditDistance(s,t)<<endl;
    return 0;
}