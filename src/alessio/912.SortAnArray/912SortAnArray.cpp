#include <bits/stdc++.h>

using namespace std;

vector<int> sortArray(vector<int> &nums)
{
    sort(nums.begin(), nums.begin() + nums.size());
    return nums;
}

int main()
{
    vector<int> nums;
    int temp;

    cout << "Input your array: " << endl;

    while (cin.peek() != '\n')
    {
        cin >> temp;
        nums.push_back(temp);
    }
    nums = sortArray(nums);
    for (int i : nums)
    {
        cout << i << ' ';
    }
    cout << endl;
}
