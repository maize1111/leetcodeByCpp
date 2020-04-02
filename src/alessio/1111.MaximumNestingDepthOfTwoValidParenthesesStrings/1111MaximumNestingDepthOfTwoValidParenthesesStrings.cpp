#include <bits/stdc++.h>

using namespace std;

vector<int> maxDepthAfterSplit(string seq)
{
    int dp = 0;
    vector<int> st;
    for (char &c : seq)
    {
        if (c == '(')
        {
            ++dp;
            st.push_back(dp % 2);
        }
        else if (c == ')')
        {
            st.push_back(dp % 2);
            --dp;
        }
    }
    return st;
}

int main(int argc, char const *argv[])
{
    string s;
    vector<int> ans;

    while (cin >> s)
    {
        ans = maxDepthAfterSplit(s);

        cout << '[';
        for (int i = 0; i < ans.size() - 1; i++)
        {
            cout << ans[i] << ',';
        }
        cout << ans[ans.size() - 1] << ']' << endl;
    }

    return 0;
}
