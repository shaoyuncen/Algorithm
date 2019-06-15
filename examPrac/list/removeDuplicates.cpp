#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode{
    ListNode(int val):val(val){}
    int val;
    ListNode* next = NULL;
};
ListNode* removeDup(ListNode* input)
{
    ListNode* Search = input;
    unordered_map<int, int> mp;
    mp[Search->val] = Search->val;
    while(Search&&Search->next)
    {
        if(mp.find(Search->next->val)!=mp.end())
        {
            ListNode* tmp = Search->next;
            Search->next = Search->next->next;
            tmp->next = NULL;
            delete tmp;
        }
        else
        {
            mp[Search->next->val] = Search->next->val;
            Search = Search->next;
        }
    }
    return input;
}
int main(int argc, char const *argv[])
{
    ListNode* head = new ListNode(1);
    ListNode* Two = new ListNode(4);
    ListNode* Three = new ListNode(2);
    ListNode* Four = new ListNode(1);
    ListNode* Five = new ListNode(3);
    ListNode* Six = new ListNode(4);
    head->next = Two;
    Two->next = Three;
    Three->next = Four;
    Four->next = Five;
    Five->next = Six;

    ListNode* output = removeDup(head);
    while(output)
    {
        cout<<output->val<<' ';
        output = output->next;
    }

    return 0;
}