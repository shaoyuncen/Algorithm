//找链表中间节点
#include <iostream>
using namespace std;
struct ListNode{
    ListNode(int val):val(val){}
    int val;
    ListNode* next;
};

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