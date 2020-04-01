#include <bits/stdc++.h>

using namespace std;

int lengthOfLastWord(string s)
{
    int count = 0;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            if (count == 0)
                continue;
            else
                break;
        }
        count++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    string s;
    while (getline(cin, s))
    {
        cout << lengthOfLastWord(s) << endl;
    }

    return 0;
}
