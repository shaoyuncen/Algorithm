#include <queue>
#include "tree.h"

void processNode(TreeNode *root);
void levelTraversal(TreeNode *root)
{
    std::queue<TreeNode *> nodeQueue;
    TreeNode *currNode;
    if (!root)
        return;

    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        currNode = nodeQueue.front();
        nodeQueue.pop();
        processNode(currNode);
        if (currNode->left)
            nodeQueue.push(currNode->left);
        if (currNode->right)
            nodeQueue.push(currNode->right);
    }
}