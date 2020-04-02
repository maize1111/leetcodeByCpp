#include <bits/stdc++.h>

using namespace std;

vector<int> maxDepthAfterSplit(string seq)
{
    int dp;
    vector<int> st;
    for (char &c : seq)
    {
        if (c == '(')
        {
            dp++;
            st.push_back(dp % 2);
        }
        else
        {
            st.push_back(dp % 2);
            dp--;
        }
    }
    return st;
}

int main(int argc, char const *argv[])
{
    string s;
    while (cin >> s)
    {
        vector<int> ans;
        ans = maxDepthAfterSplit(s);
    }
    return 0;
}
