#include "tree.h"
#include <iostream>
TreeNode* LowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(root==NULL||root==p||root==q)
        return root;
    TreeNode* left = LowestCommonAncestor(root->left, p, q);
    TreeNode* right = LowestCommonAncestor(root->right, p, q);
    if(left&&right)
        return root;
    return left? left : right;
}