//将比x小的放List左边，比x大的放List右边
#include <iostream>
using namespace std;
struct ListNode{
    ListNode(int val):val(val){}
    int val;
    ListNode* next;
};
ListNode* partition(ListNode* head, int x)
{
    if(!head)
        return head;

    ListNode* leftDummy = new ListNode(0);
    ListNode* left = leftDummy;
    ListNode* rightDummy = new ListNode(0);
    ListNode* right = rightDummy;
    ListNode* node = head;
    while(!node)
    {
        if(node->val < x)
        {
            left->next = node;
            left = left->next;
        }
        else
        {
            right->next = right;
            right = right->next;
        }
        node = node->next;
    }
    //将原链表分别分为左右后，再进行连接
    right->next = NULL;
    left->next = rightDummy->next;
    return leftDummy->next;
}  