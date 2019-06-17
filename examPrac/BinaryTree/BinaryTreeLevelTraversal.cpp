#include "tree.h"
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
//一般用两个队列或两个栈来解决
//3,9,20,null,null,15,7的树    输出  {[3],[20,9], [7,15]}
vector<vector<int>> LevelTraversal(TreeNode *root)
{
    vector<vector<int>> result;

    bool leftToRight = true;
    stack<TreeNode *> currLevel, nextLevel;
    currLevel.push(root);
    vector<int> levelVec;
    while (!currLevel.empty())
    {
        TreeNode *currNode = currLevel.top();
        ;
        currLevel.pop();

        if (currNode)
        { //当前节点不为空
            // cout<<currNode->val;
            levelVec.push_back(currNode->val);
            if (leftToRight)
            {
                nextLevel.push(currNode->left);
                nextLevel.push(currNode->right);
            }
            else
            {
                nextLevel.push(currNode->right);
                nextLevel.push(currNode->left);
            }
        }
        if (currLevel.empty())
        {
            // cout<<endl;
            swap(currLevel, nextLevel);
            leftToRight = !leftToRight;
            result.push_back(levelVec);
            levelVec.clear();
        }
    }
}
////3,9,20,null,null,15,7的树    输出  {[3],[9,20], [15,7]}
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    queue<TreeNode *> currLevel, nextLevel;
    currLevel.push(root);
    vector<int> levelVec;
    while (!currLevel.empty())
    {
        TreeNode *currNode = currLevel.front();
        currLevel.pop();
        if (currNode)
        {
            levelVec.push_back(currNode->val);
            nextLevel.push(currNode->left);
            nextLevel.push(currNode->right);
        }
        if (currLevel.empty())
        {
            swap(currLevel, nextLevel);
            if (levelVec.size() == 0)
                return result;
            result.push_back(levelVec);
            levelVec.clear();
        }
    }
    return result;
}