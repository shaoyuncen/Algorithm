#include "tree.h"
#include <iostream>

bool matchTree(TreeNode *root1, TreeNode *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->val != root2->val)
        return false;
    return matchTree(root1->left, root2->left) &&
           matchTree(root1->right, root2->right);
}

bool subTree(TreeNode* root1, TreeNode* root2)
{//判断root2是否是root1的子树
    if(root2==NULL)
        return true;
    if(root1==NULL)//root2不为空而root1为空
        return false;
    if(root1->val == root2->val)
        return matchTree(root1, root2);

    return subTree(root1->left, root2) || subTree(root1->right, root2);
}