//找环
//fast以两倍速遍历，如有loop，则fast与slow一定会在某点相遇，相遇后再让slow从head出发追赶fast，第二次相遇的节点为loop开始的位置
#include <iostream>
using namespace std;
struct ListNode{
    ListNode(int val):val(val){}
    int val;
    ListNode* next;
};
ListNode* findCircularList(ListNode* head, int x)
{
    
}  