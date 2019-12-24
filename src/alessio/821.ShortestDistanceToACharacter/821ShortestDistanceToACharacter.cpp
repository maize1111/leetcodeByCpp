#include <bits/stdc++.h>

using namespace std;

vector<int> shortestToChar(string S, char C)
{
    vector<int> res(S.size(), 0);
    int L = -1, R = -1;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] == C)
        {
            L = R;
            R = i;
            for (int j = L + 1; j < R; j++)
            {
                if (L == -1)
                    res[j] = R - j;
                else
                    res[j] = min(R - j, j - L);
            }
        }
    }
    for (int k = R + 1; k < S.size(); k++)
    {
        res[k] = k - R;
    }

    return res;
}

int main()
{
    string S = "iloveleetcode";
    char C = 'e';
    vector<int> res(S.size(), 0);

    res = shortestToChar(S, C);

    for (int temp : res)
    {
        cout << temp << '\t';
    }
}
