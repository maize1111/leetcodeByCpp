#include <bits/stdc++.h>
using namespace std;
//二维数组中的查找
/*input :matrix:[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
] target:5 /target 20


//output:true or false
*/
bool findNumberIn2DArray(vector<vector<int>> &matrix, int target)
{
    //从左下搜索到右上
    int m = matrix.size();
    if(m==0) return false;
    int n = matrix[0].size();
    if(m==0) return false;
    int i = m-1,j=0;
    while(i>=0&&j<n){
        if(matrix[i][j]>target){
            i--;

        }
        else if(matrix[i][j]<target){
            j++;

        }
        else{
            return true;
        }
    }
    return false;
    
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}};
    int target = 5;
    cout << findNumberIn2DArray(matrix, target);
    return 0;
}