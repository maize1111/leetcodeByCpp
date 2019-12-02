#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    if (m == 0)
    {
        swap(nums1, nums2);
    }
    else
    {
        int i = m - 1;
        int j = m + n - 1;
        for (int k = n - 1; k >= 0; k--)
        {
            while (i >= 0 && nums2[k] <= nums1[i])
            {
                nums1[j--] = nums1[i--];
            }
            nums1[j--] = nums2[k];
        }
    }
}

// Test Function
int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    int m = 3, n = 3;

    merge(nums1, m, nums2, n);

    for (int i = 0; i < nums1.size(); i++)
    {
        cout << nums1[i] << ' ';
    }
    cout << endl;

    return 0;
}