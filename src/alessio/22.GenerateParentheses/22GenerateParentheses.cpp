#include <bits/stdc++.h>

using namespace std;

/**
 * 解题思路：
 * 在求N个括号的排列组合时，
 * 把第N种情况（也就是N个括号排列组合）视为单独拿一个括号E出来，
 * 剩下的N-1个括号分为两部分，P个括号和Q个括号，P+Q=N-1，
 * 然后这两部分分别处于括号E内和括号E的右边，各自进行括号的排列组合。
 * 由于我们是一步步计算得到N个括号的情况的，
 * 所以小于等于N-1个括号的排列组合方式我们是已知的，
 * 且P+Q=N-1，P和Q是小于等于N-1的，
 * 所以我们能直接得到P个和Q个括号的情况，
 * 进而得到N个括号的结果。
 **/
vector<string> generateParentheses(int n)
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
        vector<string> res = generateParentheses(n);
        cout << '[' << endl;
        for (string x : res)
            cout << '"' << x << '"' << ',' << endl;
        cout << ']' << endl;
    }

    return 0;
}
