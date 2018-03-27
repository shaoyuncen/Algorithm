#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define null 0
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    //DFS
    int maxDepth_DFS(TreeNode* root) {
        return root == NULL? 0: max(maxDepth_DFS(root->left), maxDepth_DFS(root->right))+1;
    }
    //BFS
    int maxDepth_BFS(TreeNode* root)
    {
        if(root == NULL)
            return 0;
        queue<TreeNode*> q;
        int count = 0;
        q.push(root);
        while(!q.empty())
        {
            count++;
            for(unsigned int i = 0; i < q.size(); i++)
            {
                TreeNode *p = q.front();
                q.pop();
                if (p->left != NULL)
                {
                    q.push(p->left);
                }
                if (p->right != NULL)
                {
                    q.push(p->right);
                }
            } 
        }
        return count;
    }
};










