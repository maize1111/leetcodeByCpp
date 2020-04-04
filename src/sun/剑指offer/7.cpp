#include <bits/stdc++.h>
using namespace std;
//重建二叉树
/*
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
输出：  3             [3,9,20,null,null,15,7]
      / \
     9  20
       /  \
      15   7
*/
//二叉树数据结构
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *buildTree(vector<int> &preorder,int lo1,int hi1, vector<int> &inorder,int lo2,int hi2){
    if(lo1>hi1||lo2>hi2){
        return nullptr;
    }
    int rootval = preorder[lo1];
    int i = lo2;
    //寻找根节点在中序中的下标
    while(i<=hi2){
        if(inorder[i]!=rootval){
            i++;
        }
        else break;
    }
    //左右子树递归
    TreeNode* root = new TreeNode(rootval);
    root->left = buildTree(preorder,(lo1+1), (lo1+i-lo2), inorder, lo2, (i-1));
    root->right = buildTree(preorder, (lo1+i-lo2+1), hi1, inorder, (i+1), hi2);
    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    return buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}

int main()
{
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode *root = buildTree(preorder,inorder);
    return 0;
}