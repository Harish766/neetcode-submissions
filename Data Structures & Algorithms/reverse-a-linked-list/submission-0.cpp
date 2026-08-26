/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        struct ListNode *p=head;
        struct ListNode *q=head;
        struct ListNode *r=head->next;
        head->next=NULL;
        while(r!=NULL){
            q=r;
            r=r->next;
            q->next=p;
            p=q;
        }
        return p;
    }
};
