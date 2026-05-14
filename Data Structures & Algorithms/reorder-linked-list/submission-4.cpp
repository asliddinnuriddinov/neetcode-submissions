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
        ListNode* next = slow->next;
        slow->next = nullptr;
        slow = next;
        ListNode* prev = NULL;
        while(slow){
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        ListNode* currL = head;
        while(currL && prev){
            ListNode* currLNext = currL->next;
            ListNode* prevNext = prev->next;
            currL->next = prev;
            prev->next = currLNext;
            currL = currLNext;
            prev = prevNext;
        }
    }
};
