#include <iostream>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode *reverseList(ListNode *head)
{
    ListNode* newHead = NULL;
    while(head)
    {
        ListNode *nextNode = head->next;
        head->next = newHead;
        newHead = head;
        head = nextNode;
    }
    return newHead;
}//迭代
ListNode *reverseListIter(ListNode *head, ListNode *newHead)
{
    if (head == NULL)
        return newHead;
    ListNode *nextNode = head->next;
    head->next = newHead;
    return reverseListIter(nextNode, head);
}
ListNode *reverseList2(ListNode *head)
{
    return reverseListIter(head, NULL);
}
int main()
{
    
    return 0;
}