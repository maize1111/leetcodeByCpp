#include <bits/stdc++.h>

using namespace std;

int maximalRectangle(vector<vector<char>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;
    int res = 0;
    int col = matrix.size();
    int row = matrix[0].size();

    vector<int> height(row + 1);
    for (int i = 0; i < col; ++i)
    {
        stack<int> s;
        for (int j = 0; j < row + 1; ++j)
        {
            if (j < row)
            {
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0;
            }
            while (!s.empty() && height[s.top()] >= height[j])
            {
                int cur = s.top();
                s.pop();
                res = max(res, height[cur] * (s.empty() ? j : (j - s.top() - 1)));
            }
            s.push(j);
        }
    }
    return res;
}

// Test Function
int main()
{
    vector<vector<char>> matrix =
        {{'1', '0', '1', '0', '0'},
         {'1', '0', '1', '1', '1'},
         {'1', '1', '1', '1', '1'},
         {'1', '0', '0', '1', '0'}};

    cout << "Rectangle is " << maximalRectangle(matrix) << endl;

    return 0;
}
