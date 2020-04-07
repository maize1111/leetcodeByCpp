#include <bits/stdc++.h>
using namespace std;
//替换空格
/*input : s = "We are happy."
//output:"We%20are%20happy."
*/
string replaceSpace(string s)
{
    string space = "%20";
    string res;
    int n = s.size();
    if (n == 0)
        return "";
    int i = 0;
    int j = 0;
    while (i < n)
    {
        if (s[i] == ' ')
        {
            res += s.substr(j, i - j);
            res += space;
            i++;
            j = i;
        }
        else
        {
            i++;
        }
    }
    //补充最后一个子字符串
    if (j < n)
        res += s.substr(j, i - j + 1);
    return res;
}
int main()
{
    string s = "We are happy.";
    cout << replaceSpace(s);
    return 0;
}