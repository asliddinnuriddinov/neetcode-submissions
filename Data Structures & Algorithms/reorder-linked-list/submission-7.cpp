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

        ListNode* start = slow->next;
        ListNode* end = NULL;
        slow->next = NULL;
        while(start){
            ListNode* next = start->next;
            start->next = end;
            end = start;
            start = next;
        }
        start = head;
        while(end){
            ListNode* endNext = end->next;
            ListNode* startNext = start->next;

            start->next = end;
            end->next = startNext;

            start = startNext;
            end = endNext;
        }
    }
};
