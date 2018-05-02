#include <iostream>

using namespace std;
//Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode preHead(0), *p = &preHead;
    int extra = 0;
    while (l1 || l2 || extra)
    {
        if (l1)
            extra += l1->val, l1 = l1->next;
        if (l2)
            extra += l2->val, l2 = l2->next;
        p->next = new ListNode(extra % 10);
        extra /= 10;
        p = p->next;
    }
    return preHead.next;
}
int main()
{
    ListNode prehead(10), *output = &prehead;
    output->val = 1;
    cout << output->val << endl;
    return 0;
}