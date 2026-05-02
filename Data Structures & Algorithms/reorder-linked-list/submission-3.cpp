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
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast && fast->next){
            fast = fast ->next->next;
            slow = slow->next;
        }
        ListNode* slowNext = slow->next;
        slow->next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = slowNext;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        curr = head;
        while(prev){
            ListNode *currNext = curr->next, *prevNext = prev->next;
            curr->next = prev;
            prev->next = currNext;
            curr = currNext;
            prev = prevNext;
        }
    }
};
