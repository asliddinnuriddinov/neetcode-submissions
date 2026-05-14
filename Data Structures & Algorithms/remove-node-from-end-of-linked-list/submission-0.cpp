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
        ListNode dummy(0);
        dummy.next = head;
        ListNode* slow = &dummy;
        ListNode* fast = head;
        while(fast && n > 0){
            fast = fast->next;
            n--;
        }

        while(fast){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy.next;
    }
};
