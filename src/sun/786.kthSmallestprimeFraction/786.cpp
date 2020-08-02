#include <bits/stdc++.h>
using namespace std;
vector<int> kthSmallestPrimeFraction(vector<int> &A, int K)
{
    double left = 0.0;
    double right = 1.0;
    double mid;
    int p = 0, q = 1, sz = A.size(), cnt;
    while (true)
    {
        mid = left + (right - left) / 2.0;
        cnt = 0;
        p = 0;
        for (int i = 0, j = 0; i < sz; i++)
        {
            while (j < sz && A[i] > mid * A[j])
            {
                j++;
            }
            cnt += sz - j;
            if (j < sz && p * A[j] < q * A[i])
            {
                p = A[i];
                q = A[j];
            }
        }
        if (cnt == K)
        { //当前mid正好是所寻找的结果
            return {p, q};
        }
        else if (cnt < K)
        { //mid小了，所以右移left
            left = mid;
        }
        else
        { //mid大了，所以左移right
            right = mid;
        }
    }
}

int main()
{
    vector<int> A = {1, 2, 3, 5};
    int k = 3;
    vector<int> res = kthSmallestPrimeFraction(A, k);
    cout << res[0] << "   " << res[1] << endl;

    return 0;
}