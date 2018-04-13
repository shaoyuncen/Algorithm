#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
void deleteNode(ListNode *node)
{
    ListNode *p = node->next;
    node->val = p->val;
    node->next = p->next;
}
int main()
{
    
    return 0;
}