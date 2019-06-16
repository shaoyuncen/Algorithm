#include "tree.h"
#include <vector>
#include <stack>
void preOrderTraversal(TreeNode* root)
{
    if(!root)
        return;
    visit(root);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
//非递归
std::vector<int> preOrderTraversal2(TreeNode* root)
{
    std::vector<int> result;
    if(root==NULL)
        return result;
    std::stack<TreeNode*> s;
    s.push(root);
    while(!s.empty())
    {
        TreeNode* node = s.top();
        s.pop();
        result.push_back(node->val);
        //因为栈先进后出，所以压栈时先右后左
        if(node->right!=NULL)
            s.push(node->right);
        if(node->left!=NULL)
            s.push(node->left);
    }
    return result;
}