//从有序链表删除重复元素
//遍历
//遇到当前节点与下个节点相同，删除下个节点
//将当前节点的next指向下下个节点，
//直到当相邻节点不等时再移动到下个节点

ListNode* deleteDuplicate(ListNode* head)
{
    if(head==NULL)
        return NULL;
    
    ListNode* node = head;
    while(node->next != NULL)
    {
        if(node->val == node->next->val)
        {
            ListNode* tmp = node->next;
            node->next = node->next->next;
            delete tmp;
        }
        else
        {
            node = node->next;
        }
        return head;
        
    }
}