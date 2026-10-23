class Node {
public:
    Node* next = NULL;
    Node* prev = NULL;
    int key, val;
    Node(int key, int val) : key(key), val(val){};
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
        Node* nodePrev = node->prev;
        Node* nodeNext = node->next;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
    }
public:
    Node left, right;
    unordered_map<int, Node*> mp {};
    int cap;
    LRUCache(int capacity) : cap(capacity), left(0, 0), right(0, 0) {
        left.next = &right;
        right.prev = &left;
    }
    
    int get(int key) {
        if(mp.contains(key)){
            Node* node = mp[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.contains(key)){
            Node* node = mp[key];
            node->val = value;
            remove(node);
            insert(node);
            return;
        }
        Node* node = new Node(key, value);
        mp[key] = node;
        insert(node);

        if(mp.size() > cap){
            Node* node = left.next;
            mp.erase(node->key);
            remove(node);
            delete node;
        }
    }
};
