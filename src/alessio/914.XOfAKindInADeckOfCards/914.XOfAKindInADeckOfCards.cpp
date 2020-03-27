#include <bits/stdc++.h>

using namespace std;

bool hasGroupSizeX(vector<int> &deck)
{
    int mincnt = INT_MAX;
    if (deck.size() == 1)
        return false;
    map<int, int> temp;
    for (int i : deck)
    {
        temp[i]++;
    }
    map<int, int>::iterator iter;
    vector<int> vec;
    for (iter = temp.begin(); iter != temp.end(); iter++)
    {
        vec.push_back(iter->second);
        mincnt = min(mincnt, iter->second);
    }
    if (mincnt <= 1)
        return false;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = i; j < vec.size(); j++)
        {
            // use c++17/20 to compile this file with supporting gcd()
            if (gcd(vec[i], vec[j]) < 2)
                return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    vector<int> test = {1, 1, 2, 2, 3, 3, 2, 2};
    bool res = hasGroupSizeX(test);
    cout << res;
    return 0;
}
