#include "tree.h"
#include "../list/list.h"
#include <iostream>
using namespace std;

ListNode* getMidPoint(ListNode* head)
{
    ListNode* fast=head;
    ListNode* slow=head;
    while(fast&&fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}
ListNode* getLastPoint(ListNode* head, ListNode* midPoint)
{
    while(head&&midPoint)
    {
        if(head->next == midPoint)
            return head;
        head = head->next;
    }
    return NULL;
}
TreeNode* sortedListToBST(ListNode* head) 
{
    if(!head)
        return NULL;
    if(!head->next)
    {//无后继节点
        TreeNode* parent = new TreeNode(head->val);
        return parent;
    }

    ListNode* midPoint = getMidPoint(head);
    TreeNode* root = new TreeNode(midPoint->val);

    ListNode* leftLast = getLastPoint(head, midPoint);
    leftLast->next = NULL;
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(midPoint->next);
    return root;
}