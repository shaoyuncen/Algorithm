//找离末尾k个位置的链表
#include <iostream>
using namespace std;
struct ListNode{
    ListNode(int val):val(val){}
    int val;
    ListNode* next;
};
ListNode* findKthtoLast(ListNode* head, int k)
{
    ListNode* fast = head, *slow = head;
    if(head==NULL || k < 0)
        return NULL;
    for(int i = 0; i < k; ++i)
        fast = fast->next;
    if(fast == NULL)
        return NULL;
    while(fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}  