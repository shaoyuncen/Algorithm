#include "tree.h"
#include "../list/list.h"
#include <iostream>
using namespace std;

TreeNode* sortedListToBST(ListNode* head) 
{
    if(!head)
        return NULL;
    if(!head->next)
    {
        TreeNode* parent = new TreeNode(head->val);
        return parent;
    }
}