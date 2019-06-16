#include "tree.h"
#include <iostream>
#include <vector>
using namespace std;
TreeNode* helper(vector<int> nums, int first, int last)
{
    if(first > last)
        return NULL;
    if(first == last)
    {
        TreeNode* parent = new TreeNode(nums[first]);
        return parent;
    }
    int mid = (first + last)/2;
    TreeNode* leftChild = helper(nums, first, mid);
    TreeNode* rightChild = helper(nums, mid+1, last);
    
    TreeNode* parent= new TreeNode(nums[mid]);
    parent->left = leftChild;
    parent->right = rightChild;
    return parent;
}
TreeNode* ArrayToBST(vector<int>& nums)
{
    if(nums.size() == 0)
        return NULL;
    if(nums.size() == 1)
    {
        TreeNode* parent = new TreeNode(nums[0]);
        return parent;
    }
    int first = 0;
    int last = (int)nums.size()-1;
    return helper(nums, first, last);
}