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
        curr = &dummy;

        while(head){
            Node* base = mp[head];
            Node* next = mp[head->next];
            Node* random = mp[head->random];
            base->next = next;
            base->random = random;

            curr->next = base;
            curr = curr->next;
            head = head->next;
        }
        return dummy.next;
    }
};
