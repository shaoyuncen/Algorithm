//找链表中间节点
#include <iostream>
#include "list.h"
using namespace std;


ListNode* midPoint(ListNode* head)
{
    ListNode* fast = head, *slow = head;
    if(head == NULL)
        return NULL;

    while(fast->next && slow->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    } 
    return slow;
}  