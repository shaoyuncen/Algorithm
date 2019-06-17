//判断是否是对称的, 把右子树翻转一下，比较两棵树是否相等
#include "tree.h"
#include <iostream>
using namespace std;


TreeNode* invert(TreeNode* root)
{
    if(root)
    {
        TreeNode* left = invert(root->left);
        root->left = invert(root->right);
        root->right = left;
    }
    return root;
}
bool isSame(TreeNode* root1, TreeNode* root2)
{
    if(root1==NULL&&root2==NULL)
        return true;
    if(root1&&root2)
        return (root1->val==root2->val)&&
            isSame(root1->left, root2->left)&&
            isSame(root1->right, root2->right);
    return false;
}
bool isSymmetric(TreeNode* root) {
    if(!root)
        return true;
    root->right = invert(root->right);
    return isSame(root->left, root->right);
}