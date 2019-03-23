//翻转二叉树
TreeNode* invertTree(TreeNode* root)
{
    if(root == NULL)
        return NULL;
    TreeNode *tmpNode = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(root->tmpNode);
}