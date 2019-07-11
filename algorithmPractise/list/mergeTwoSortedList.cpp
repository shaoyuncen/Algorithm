#include "list.h"
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode pseudoHead(-1);
        ListNode* tail = &pseudoHead, *pNode = NULL;
        while(l1 && l2){
            if(l1->val < l2->val){
                pNode = l1;
                l1 = l1->next;
            }else{
                pNode = l2;
                l2 = l2->next;
            }
            tail->next = pNode;
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return pseudoHead.next;
    }