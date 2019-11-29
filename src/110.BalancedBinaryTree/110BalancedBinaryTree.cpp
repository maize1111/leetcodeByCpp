#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isBalanced(TreeNode *root, int *deepth)
{
    if (root == NULL)
    {
        *deepth = 0;
        return true;
    }

    int leftDeepth, rightDeepth;
    bool left = isBalanced(root->left, &leftDeepth);
    bool right = isBalanced(root->right, &rightDeepth);

    if (left && right)
    {
        int diff = rightDeepth - leftDeepth;
        if (abs(diff) <= 1)
        {
            *deepth = 1 + (leftDeepth > rightDeepth ? leftDeepth
                                                    : rightDeepth);
            return true;
        }
    }

    return false;
}

bool isBalanced(TreeNode *root)
{
    int deepth = 0;
    return isBalanced(root, &deepth);
}

// Test Function
int main()
{
    return 0;
}