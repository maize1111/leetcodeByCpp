#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int> &nums, int val)
{
    vector<int>::iterator it;
    for (it = nums.begin(); it != nums.end();)
    {
        if (*it == val)
            it = nums.erase(it);
        else
            ++it;
    }
    return nums.size();
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
}
