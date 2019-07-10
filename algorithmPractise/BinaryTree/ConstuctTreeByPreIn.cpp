//preorder = [3,9,20,15,7]
//inorder = [9,3,15,20,7]
//     3
//    / \
//   9  20
//     /  \
//    15   7
#include "tree.h"
#include <iostream>
#include <vector>
using namespace std;
TreeNode* build(vector<int>& preorder, vector<int>& inorder,  
                    int p1, int p2, 
                    int i1, int i2)
    {
        if(p1>p2)    
            return NULL;
        TreeNode* root = new TreeNode(preorder[p1]);
        int i;
        for(i = i1; i <= i2; ++i)
            if(preorder[p1] == inorder[i])
                break;
        root->left = build(preorder, inorder, p1+1, p1+i-i1, i1, i-1);
        root->right = build(preorder, inorder, p1+1+i-i1, p2, i+1, i2);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
