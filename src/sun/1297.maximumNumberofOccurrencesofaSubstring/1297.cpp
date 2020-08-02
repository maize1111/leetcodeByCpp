#include <bits/stdc++.h>
using namespace std;
int maxFreq(string s, int maxLetters, int minSize, int maxSize)
{
    int count = 0;
    int res = 0;
    int cnt[26] = {0};
    unordered_map<string, int> m;
    for (int i = 0; i < minSize; i++)
    {
        if (cnt[s[i] - 'a'] == 0)
        {
            count++;
        }
        cnt[s[i] - 'a']++;
    }
    if (count <= maxLetters)
    {
        m[s.substr(0, minSize)]++;
    }
    for (int i = minSize; i < s.size(); i++)
    {
        string str = s.substr(i - minSize + 1, minSize);
        int remove = i - minSize;
        if (s[i] != s[remove])
        {
            if (cnt[s[i] - 'a'] == 0)
            {
                count++;
            }
            if (cnt[s[remove] - 'a'] == 1)
            {
                count--;
            }
        }

        cnt[s[i] - 'a']++;
        cnt[s[remove] - 'a']--;

        if (count <= maxLetters)
        {
            m[str]++;
        }
    }
    unordered_map<string, int>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << it->first << "    " << it->second << endl;
        res = max(res, it->second);
        it++;
    }
    return res;
}

int main()
{
    string s = "adfdaefadcebdbd";
    int maxLetters = 1;
    int minSize = 5;
    int maxSize = 10;
    int res = maxFreq(s, maxLetters, minSize, maxSize);
    cout << res << endl;
    return 0;
}
//"aababcaab"
// 2
// 3
// 4

// "adfdaefadcebdbd"
// 1
// 5
// 10
