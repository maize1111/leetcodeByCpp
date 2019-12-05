#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int start = 0, end = 0, result = 0, i = 0, j = seats.size() - 1;
        while (!seats[i++])
            start++;
        while (!seats[j--])
            end++;
        result = max(start, end);
        start = 0;
        while (i <= j)
        {
            while (!seats[i++])
                start++;
            result = max(result, (++start) >> 1);
            start = 0;
        }
        return result;
    }
};
