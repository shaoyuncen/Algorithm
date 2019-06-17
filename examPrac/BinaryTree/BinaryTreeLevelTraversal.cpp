#include "tree.h"
#include <iostream>
//一般用两个队列或两个栈来解决
//3,9,20,null,null,15,7的树    输出  {[3],[20,9], [7,15]}
vector<vector<int>> LevelTraversal(TreeNode* root)
{
    vector<vector<int>> result;

    bool leftToRight=true;
    stack<TreeNode*> currLevel, nextLevel;
    currLevel.push(root);
    vector<int> levelVec;
    while(!currLevel.empty()){
        TreeNode* currNode = currLevel.top();;
        currLevel.pop();
        
        if(currNode)
        {//当前节点不为空
            // cout<<currNode->val;
            levelVec.push_back(currNode->val);
            if(leftToRight)
            {
                currLevel.push(currNode->left);
                currLevel.push(currNode->right);
            }
            else
            {
                currLevel.push(currNode->right);
                currLevel.push(currNode->left);
            }
        }   
        if(currLevel.empty())
        {
            // cout<<endl;
            swap(currLevel, nextLevel);
            leftToRight = !leftToRight;
            result.push_back(levelVec);
            levelVec.clear();
        }
    }

}