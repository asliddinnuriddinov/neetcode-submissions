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
        tail->next = mp[head];
        tail = tail->next;
        curr = head;
        while(curr){
            Node* next = mp[curr->next];
            Node* random = mp[curr->random];

            tail->next = next;
            tail->random = random;
            curr = curr->next;
            tail = tail->next;
        }

        return dummy.next;
    }
};
