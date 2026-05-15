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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(l1 || l2){
            int currSum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            int digit = currSum % 10;
            carry = currSum / 10;
            tail->next = new ListNode(digit);
            tail = tail->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry){
            tail->next = new ListNode(carry);
        }
        return dummy.next;
    }
};
