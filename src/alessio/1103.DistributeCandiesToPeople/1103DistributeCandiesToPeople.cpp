#include <bits/stdc++.h>

using namespace std;

vector<int> distributeCandies(int candies, int num_people)
{
    vector<int> ans(num_people, 0);
    if (candies == 0)
        return {0};
    int rows = candies / (num_people * (num_people + 1) / 2);
    int left = candies;
    if (rows == 0)
    {
        int k = 0, m = 0;
        while (left > k + 1)
        {
            ans[k] = k + 1;
            k++;
            left = left - k;
        }
        ans[k] = left;
    }
    else
    {
        int j = 0;
        while (left > 0)
        {
            ans[j % num_people] += (j + 1);
            left -= (j + 1);
            j++;
        }
        ans[(j - 1) % num_people] += left;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int candies = 7, num_people = 4;
    vector<int> ans = distributeCandies(candies, num_people);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << '\t';
    }
    cout << endl;

    return 0;
}
