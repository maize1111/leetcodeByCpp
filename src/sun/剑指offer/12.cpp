#include <bits/stdc++.h>
using namespace std;
//二维数组中的查找
/*输入：board = [["A","B","C","E"],
                ["S","F","C","S"],
                ["A","D","E","E"]], 
       word = "ABCCED"
输出：true

*/
int diff[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool backtrack(vector<vector<char>> &board, string word, int start, int i, int j)
{
    //超出边界或者字符不匹配
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[start])
    {
        return false;
    }
    //字符串完全匹配
    if (start == word.size() - 1 && (word[start] == board[i][j]))
    {
        return true;
    }
    //标记已访问字符
    char tmp = word[start];
    board[i][j] = '*';
    //向四个方向寻找前进方向
    for (int k = 0; k < 4; k++)
    {
        int x = i + diff[k][0], y = j + diff[k][1];
        if (i >= 0 && j >= 0 && i < board.size() && j < board[0].size())
        {
            if (backtrack(board, word, start + 1, x, y))
            {
                return true;
            }
        }
    }
    //恢复字符
    board[i][j] = tmp;
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    bool res = false;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (backtrack(board, word, 0, i, j))
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    cout << exist(board, word);
    return 0;
}