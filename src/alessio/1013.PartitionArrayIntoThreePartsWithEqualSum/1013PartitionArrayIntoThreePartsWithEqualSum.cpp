#include <bits/stdc++.h>

using namespace std;

bool canThreePartsEqualSum(vector<int> &A)
{
    int sum = accumulate(A.begin(), A.end(), 0);
    if (sum % 3 != 0)
        return false;
    int i = 0, sum1 = 0;
    while (i < A.size())
    {
        sum1 += A[i];
        if (sum1 == sum / 3)
            break;
        i++;
    }
    if (sum1 != sum / 3)
        return false;
    int j = i + 1, sum2 = 0;
    while (j < A.size() - 1)
    {
        sum2 += A[j];
        if (sum2 == sum / 3)
            return true;
        j++;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    vector<int> A = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    cout << canThreePartsEqualSum(A) << endl;
    return 0;
}
