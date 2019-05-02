#include "../common.h"

using namespace std;

/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:
    Input: 1->2->3->4->5->NULL
    Output: 1->3->5->2->4->NULL
Example 2:
    Input: 2->1->3->5->6->4->7->NULL
    Output: 2->3->6->7->1->5->4->NULL
*/
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *pre = head, *cur = head->next;
        while (cur && cur->next) {
            ListNode *tmp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = tmp;
            cur = cur->next;
            pre = pre->next;
        }

        return head;
    }
};
int main()
{
    vector<int> nums({0,1, 2, 3, 4, 5, 6});
    ListNode *head = new ListNode(nums[0]);
    ListNode *conPointer = head;

    for (auto it = nums.begin()+1; it != nums.end();++it)
    {
        ListNode* tmpNode = new ListNode(*it);
        conPointer->next = tmpNode;
        conPointer = conPointer->next;
    }
    conPointer = head;
    while(conPointer)
    {
        cout << conPointer->val << ' ';
        conPointer = conPointer->next;
    }
    cout << endl;

    Solution sol;
    conPointer = sol.oddEvenList(head);
    while(conPointer)
    {
        cout << conPointer->val << ' ';
        conPointer = conPointer->next;
    }
    return 0;
}