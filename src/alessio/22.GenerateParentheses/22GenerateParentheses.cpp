#include <bits/stdc++.h>

using namespace std;

vector<string> generateParenthesis(int n)
{
    if (n == 0)
        return {};

    // 储存<=n的各种排列组合情况
    vector<vector<string>> res(n + 1);
    res[0] = {""};
    res[1] = {"()"};

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            for (string temp1 : res[j])
            {
                for (string temp2 : res[i - j - 1])
                {
                    string str = "(" + temp1 + ")" + temp2;
                    res[i].push_back(str);
                }
            }
        }
    }
    return res[n];
}

int main()
{
    int n;
    while (cin >> n)
    {
        vector<string> res = generateParenthesis(n);
        cout << '[' << endl;
        for (string x : res)
            cout << '"' << x << '"' << ',' << endl;
        cout << ']' << endl;
    }

    return 0;
}