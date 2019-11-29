class Solution
{
public:
    int romanToInt(string s)
    {
        int ans = 0;
        if (s.size() == 0)
            return 0;
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (getValue(s[i]) >= getValue(s[i + 1]))
            {
                ans += getValue(s[i]);
            }
            else
            {
                ans -= getValue(s[i]);
            }
        }
        ans += getValue(s[s.size() - 1]);
        return ans;
    }
    int getValue(char c)
    {
        switch (c)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }
};