class Node {
    public:
        Node* next;
        Node* prev;
        int key, val;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
};

class LRUCache {
    int cap;
    Node left;
    Node right;
    unordered_map<int, Node*> mp {};

private:
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }

    void insert(Node* node){
        Node* rightPrev = right.prev;
        rightPrev->next = node;
        node->next = &right;
        node->prev = rightPrev;
        right.prev = node;
    }
public:
    LRUCache(int capacity) : cap(capacity), left(0, 0), right(0, 0) {
        left.next = &right;
        right.prev = &left;
    }
    
    int get(int key) {
        if(mp.contains(key)){
            Node* curr = mp[key];
            remove(curr);
            insert(curr);

            return curr->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.contains(key)){
            Node* curr = mp[key];
            curr->val = value;
            remove(curr);
            insert(curr);
            return;
        }

        Node* curr = new Node(key, value);
        mp[key] = curr;
        insert(curr);

        if(mp.size() > cap){
            Node* lru = left.next;
            remove(lru);
            mp.erase(lru->key);
            delete lru;
        }
    }
};
