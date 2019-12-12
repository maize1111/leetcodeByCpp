#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    int len = nums.size();
    for (int i = 0; i < len;)
    {
        if (nums[i] == val)
        {
            for (int j = i; j < len - 1; j++)
            {
                nums[j] = nums[j + 1];
            }
            len--;
        }
        else
        {
            i++;
        }
    }
    return len;
}

int main()
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    int len = removeElement(nums, val);
    for (int i = 0; i < len; i++)
    {
        cout << nums[i] << ' ';
    }
    cout << endl;

    return 0;
}
