//先交换两个prev节点的next指针的值
//再交换这个两个节点的next指针的值
#include <iostream>
#include "list.h"
using namespace std;


ListNode* swapPairs(ListNode* head)
{
    if(!head)
        return head;
    
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* node1 = head, *node2 = head->next;
    while(node1&&node1->next)
    {
        node2 = node1->next;
        //swap the "next" of prev nodes
        prev->next = node1->next;//=node2

        //swap the "next" of curr nodes
        node1->next = node2->next;
        node2->next = node1;

        prev = node1;
        node1 = prev->next;
    }
    return dummy->next;
}