#include "tree.h"
#include <stdio.h>
//打印BST中k1-k2

void printRange(TreeNode* root, int k1, int k2)
{
    if(!root)
        return;
    if(root->val > k1)
        printRange(root->left, k1, k2);
    if(root->val >= k1 && root->val <= k2)
        printf("data: %d", root->val);
    if(root->val < k2)
        printRange(root->right, k1, k2);
}   