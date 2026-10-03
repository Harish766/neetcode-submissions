class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* head = l1;
        ListNode* second = l2;

        vector<int> check;
        vector<int> store;

        // Put digits into vectors
        while(head != NULL || second != NULL) {

            if(head == NULL) {
                store.push_back(second->val);
                second = second->next;
            }
            else if(second == NULL) {
                check.push_back(head->val);
                head = head->next;
            }
            else {
                check.push_back(head->val);
                head = head->next;

                store.push_back(second->val);
                second = second->next;
            }
        }

        // Make both vectors the same size
        while(check.size() < store.size()) {
            check.push_back(0);
        }

        while(store.size() < check.size()) {
            store.push_back(0);
        }

        // Add the numbers
        vector<int> ans;
        int carry = 0;

        int p = 0;

        while(p < check.size()) {

            int summn = check[p] + store[p] + carry;

            ans.push_back(summn % 10);

            carry = summn / 10;

            p++;
        }

        // If carry is left
        if(carry != 0) {
            ans.push_back(carry);
        }

        // Create linked list
        ListNode* first = new ListNode(ans[0]);
        ListNode* tail = first;

        int i = 1;

        while(i < ans.size()) {

            ListNode* curr = new ListNode(ans[i]);

            tail->next = curr;
            tail = curr;

            i++;
        }

        return first;
    }
};