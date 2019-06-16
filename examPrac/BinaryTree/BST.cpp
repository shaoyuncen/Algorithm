#include "tree.h"
#include <math.h>
#define max(a, b) a>b? a:b
int level(TreeNode* root)
{
    if(!root)
        return 0;
    return max(level(root->left), level(root->right))+1;
}
int isBalancedTreeHelper(TreeNode* root)
{
    if(!root)
        return 0;
    int leftHeight = isBalancedTreeHelper(root->left);
    if(leftHeight == -1)
        return -1;
    int rightHeight = isBalancedTreeHelper(root->right)
    if(rightHeight == -1)
        return -1;
    if(abs(leftHeight-rightHeight)>1)
        return -1;
    
    return max(leftHeight, rightHeight)+1;
}
bool isBalancedTree(TreeNode* root)
{
    return (isBalancedTreeHelper(root)!=-1);
} 
bool isBalanced(TreeNode* root)
{
    if(!root)
        return true;
    int factor = abs(level(root->left)-level(root->right));
    return factor < 2 && isBalanced(root->left) && isBalanced(root->right);
}
