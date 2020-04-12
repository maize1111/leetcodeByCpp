#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &matrix)
{
    //原地操作 (i,j)->(j,n-i-1)
    int n = matrix.size();
    if (n == 0)
        return;
    for (int i = 0; i < (n + 1) / 2; i++)
    {
        for (int j = i; j < (n - i - 1); j++)
        {
            int x = i, y = j;
            int next, cur = matrix[i][j];
            for (int k = 0; k < 4; k++)
            {
                next = matrix[y][n - x - 1];
                matrix[y][n - x - 1] = cur;
                cur = next;
                int t = y;
                y = n - x - 1;
                x = t;
            }
        }
    }
}
int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    rotate(matrix);
    cout << matrix[0][0] << endl;
    return 0;
}