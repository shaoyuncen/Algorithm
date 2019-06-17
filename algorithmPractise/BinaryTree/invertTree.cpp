#include "tree.h"

TreeNode* invertTree(TreeNode* root)
{
    if(root)
    {
        TreeNode* left = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = left;
    }
    return root;
}