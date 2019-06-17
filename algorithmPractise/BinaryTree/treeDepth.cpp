#include "tree.h"
#include <iostream>
#define max(a, b) a>b?a:b
int treeDepth(TreeNode* root)
{
    if(root==NULL)
        return 0;
    return max(treeDepth(root->left), treeDepth(root->right))+1;
}