/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp {};
        Node* curr = head;
        while(curr){
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        Node dummy(0);
        Node* tail = &dummy;
        while(head){
            Node* node = mp[head];
            node->next = mp[head->next];
            node->random = mp[head->random];
            tail->next = node;
            head = head->next;
            tail = tail->next;
        }
        return dummy.next;
    }
};
