//将比x小的放List左边，比x大的放List右边
#include <iostream>
using namespace std;
struct ListNode{
    ListNode(int val):val(val){}
    int val;
    ListNode* next;
};

ListNode* reverseList(ListNode* head)
{//迭代
    ListNode* prev = NULL;
    while(head)
    {
        ListNode* curr = head;
        head = head->next;
        curr->next = prev;
        prev = curr;
    }
    return prev;
}  

ListNode* reverseList2(ListNode* head)
{
    if(!head) return head;
    if(!head->next) return head;
    ListNode* newHead = reverseList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return newHead;
}