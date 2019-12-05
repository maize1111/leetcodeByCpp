#include <bits/stdc++.h>

using namespace std;

string removeDuplicates(string s, int k)
{
    vector<pair<char, int>> st{{'*', 0}};
    for (char c : s)
    {
        if (c != st.back().first)
        {
            st.emplace_back(c, 1);
        }
        else if (++st.back().second == k)
        {
            st.pop_back();
        }
    }
    string res;
    for (const auto &p : st)
    {
        res.append(p.second, p.first);
    }
    return res;
}

int main()
{
    string s;
    int k;
    while (cin >> s >> k)
    {
        cout << "s: " + s << endl;
        cout << removeDuplicates(s, k) << endl;
    }

    return 0;
}
