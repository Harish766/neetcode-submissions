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
        ListNode* first=list1;
        ListNode* second=list2;
        int count=1;
        
        ListNode* head = NULL;
        ListNode* tail = NULL;
        while(first!=NULL || second!=NULL){
            int value;
            if(first==NULL){
                value=second->val;
                second=second->next;
            }
            else if(second == NULL){
                value=first->val;
                first=first->next;
            }
           else if(first->val >=second->val){
                value=second->val;
                second=second->next;
            }
            else{
                value=first->val;
                first=first->next;
            }
            if(head==NULL){
                head=new ListNode(value);
                tail=head;
            }else{
                tail->next=new ListNode(value);
                tail=tail->next;
            }
        }
        return head;
    }
};
