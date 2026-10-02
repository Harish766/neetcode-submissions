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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode*p=list1;
        ListNode*q=list2;
        ListNode*head=NULL;
        ListNode*tail=NULL;
        while(p!=NULL || q!=NULL){
            int value;
            if(p==NULL){
                value=q->val;
                q=q->next;
            }
            else if(q==NULL){
                value=p->val;
                p=p->next;
            }
            else if(p->val >= q->val){
                value=q->val;
                q=q->next;
            }
            else{
                value=p->val;
                p=p->next;
            }
            if(head==NULL){
                head= new ListNode(value);
                tail=head;
            }
            else{
                ListNode *upcom = new ListNode(value);
                tail->next=upcom;
                tail=upcom;
            }
        }
        return head;
    }
};
