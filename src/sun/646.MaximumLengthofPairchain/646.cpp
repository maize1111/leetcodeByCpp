#include <bits/stdc++.h>
using namespace std;
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end());
    vector<int> dp(pairs.size(), 0);
    dp[0] = 1;
    for (int i = 1; i < pairs.size(); i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (pairs[j][1] < pairs[i][0])
            {
                dp[i] = max(dp[i], dp[j]);
            }
        }
        dp[i]++;
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    vector<vector<int>> pairs = {{1,2},{3,7},{2,3},{5,9},{4,6},{3,4}};
    int res = findLongestChain(pairs);
    cout<<res<<endl;

    return 0;
}