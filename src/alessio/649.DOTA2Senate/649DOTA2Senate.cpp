// 执行用时 : 8 ms, 在所有 cpp 提交中击败了 88.76 % 的用户
// 内存消耗 : 8.7 MB, 在所有 cpp 提交中击败了 100.00 % 的用户

#include <bits/stdc++.h>

using namespace std;

// 贪心算法
// I won't leave DOTA 2. It's my baby.
// Wings Gaming
string predictPartyVictory(string senate)
{
    // 天辉 夜魇 近卫 天灾
    bool Radiant = true, Dire = true;
    int flag = 0;

    while (Radiant && Dire)
    {
        Radiant = false, Dire = false;
        for (int i = 0; i < senate.size(); ++i)
        {
            if (senate[i] == 'R')
            {
                Radiant = true;
                if (flag < 0)
                    senate[i] = 'X';
                ++flag;
            }
            else if (senate[i] == 'D')
            {
                Dire = true;
                if (flag > 0)
                    senate[i] = 'X';
                --flag;
            }
        }
    }
    return flag > 0 ? "Radiant" : "Dire";
}

// Test Function
int main()
{
    string senate;
    while (cin >> senate)
    {
        cout << predictPartyVictory(senate) << endl;
    }

    return 0;
}
