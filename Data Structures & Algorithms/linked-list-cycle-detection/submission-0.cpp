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
    bool hasCycle(ListNode* head) {
        unordered_map<ListNode*,bool> map;
        while(head!=NULL){
            if(map.find(head)==map.end()){
                map[head]=true;
                head=head->next;
            }else{
                return true;
            }
        }
        return false;
    }
};
