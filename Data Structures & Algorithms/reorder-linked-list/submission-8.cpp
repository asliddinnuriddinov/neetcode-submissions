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
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* curr = slow->next;
        slow->next = NULL;
        slow = NULL;
        while(curr){
            ListNode* next = curr->next;
            curr->next = slow;
            slow = curr;
            curr = next;
        }
        curr = head;
        while(slow){
            ListNode* currNext = curr->next;
            ListNode* slowNext = slow->next;
            curr->next = slow;
            slow->next = currNext;
            curr = currNext;
            slow = slowNext;
        }
    }
};
