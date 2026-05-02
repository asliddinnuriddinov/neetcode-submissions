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
ListNode* merge2List(ListNode* f, ListNode* s) {
    ListNode dummy(0);
    ListNode* tail = &dummy;

    while (f && s) {
        if (f->val < s->val) {
            tail->next = f;
            f = f->next;
        } else {
            tail->next = s;
            s = s->next;
        }
        tail = tail->next;
    }
    if (f) {
        tail->next = f;
    } else if (s) {
        tail->next = s;
    }
    return dummy.next;
}
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        if (lists.size() == 1)
            return lists[0];
        ListNode* result = lists[0];
        for (int i = 1; i < lists.size(); i++) {
            result = merge2List(result, lists[i]);
        }

        return result;
    }
};
