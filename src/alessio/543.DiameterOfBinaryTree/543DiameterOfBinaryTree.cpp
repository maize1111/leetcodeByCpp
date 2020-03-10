#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int res = 0;

int diameterOfBinaryTree(TreeNode *root)
{
    dfs(root);
    return res;
}

int dfs(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int left = dfs(root->left);
    int right = dfs(root->right);
    if (root->left != NULL)
        left++;
    if (root->right != NULL)
        right++;
    res = max(right + left, res);
    return max(left, right);
}

int main(int argc, char const *argv[])
{
    return 0;
}
