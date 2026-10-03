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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p=head;
        ListNode *q=NULL;
        int count=0;
        while(p!=NULL){
            p=p->next;
            count++;
        }
        p=head;
        if(count==n){
            head=head->next;
            delete p;
            return head;
        }
        for(int i=1;i<=count-n;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete p;
        return head;
    }
};
