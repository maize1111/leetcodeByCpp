#include <bits/stdc++.h>

using namespace std;

int lastRemaining(int n, int m)
{
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        res = (m + res) % (i + 1);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n, m;
    while (cin >> n >> m)
    {
        cout << lastRemaining(n, m) << endl;
    }
    return 0;
}
