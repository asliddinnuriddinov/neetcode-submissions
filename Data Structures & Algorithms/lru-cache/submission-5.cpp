class Node {
public:
    Node* next = NULL, *prev = NULL;
    int key, val;
    Node(int key, int val) : key(key), val(val) {};
};

class LRUCache {
private:
    void insert(Node* node){
        Node* rightPrev = right.prev;
        rightPrev->next = node;
        node->prev = rightPrev;
        node->next = &right;
        right.prev = node;
    }
    void remove(Node* node){
        Node* prev = node->prev;
        Node* next = node->next;

        prev->next = next;
        next->prev = prev;
    }
public:
    Node left, right;
    int cap;
    unordered_map<int, Node*> mp {};
    LRUCache(int capacity) : cap(capacity), left(0, 0), right(0, 0) {
        left.next = &right;
        right.prev = &left;
    }
    
    int get(int key) {
        if(mp.count(key)){
           Node* node = mp[key];
           remove(node);
           insert(node);
           return node->val; 
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.count(key)){
            Node* node = mp[key];
            remove(node);
            insert(node);
            node->val = value;
            return;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        insert(node);
        if(cap < mp.size()){
            Node* node = left.next;
            remove(node);
            mp.erase(node->key);
            delete node;
        }
    }
};
