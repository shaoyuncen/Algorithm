//翻转m,n的链表
#include <iostream>

using namespace std;
struct ListNode{
    ListNode(int val):val(val){}
    int val;
    ListNode* next=NULL;
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
ListNode* reverseListMN(ListNode* head, int m, int n)
{
    ListNode* op = head;
    int count = 1;
    ListNode* left = NULL;
    ListNode* right = NULL;

    while(op)
    {//截取
        if(count==m-1)
            left = op;
        if(count==n&&op->next!=NULL)
        {
            right = op->next;
            op->next = NULL;
            break;
        }
        count++;
        op = op->next;
    }

    if(m <= 1)
    {
        ListNode* oldHead = head;
        ListNode* newHead = reverseList(head);
        oldHead->next = right;
        return newHead;
    }
    else
    {
        ListNode* oldHead = left->next;
        ListNode* newHead = reverseList(left->next);
        oldHead->next = right;
        left->next = newHead;
        return head;
    }
    
}
int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    ListNode* Two = new ListNode(2);
    ListNode* Three = new ListNode(3);
    ListNode* Four = new ListNode(4);
    ListNode* Five = new ListNode(5);
    ListNode* Six = new ListNode(6);
    head->next = Two;
    Two->next = Three;
    Three->next = Four;
    Four->next = Five;
    Five->next = Six;

    ListNode* output = reverseListMN(head, 2, 5);
    while(output)
    {
        cout<<output->val<<' ';
        output = output->next;
    }

    return 0;
}