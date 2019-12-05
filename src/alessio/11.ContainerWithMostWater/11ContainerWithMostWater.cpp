#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int> &height)
{
    // 双指针: left, right
    int left = 0, right = height.size() - 1;
    int maxArea = 0;
    while (left < right)
    {
        int currentArea, currentHeight, currentWidth;
        currentWidth = right - left;
        if (height[right] > height[left])
        {
            currentHeight = height[left++];
        }
        else
        {
            currentHeight = height[right--];
        }
        currentArea = currentHeight * currentWidth;
        if (currentArea > maxArea)
        {
            maxArea = currentArea;
        }
    }
    return maxArea;
}

//Test Function
int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;

    return 0;
}
