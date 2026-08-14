    class Node {
        public:
            int key = 0, val = 0;
            Node* next = nullptr;
            Node* prev = nullptr;
            Node(int key, int val){
                this->key = key, this->val = val;
            }
    };
    
    class LRUCache {
    private:
        int cap;
        Node left;
        Node right;
        unordered_map<int, Node*> mp {};

        void remove(Node* node){
            Node* prev = node->prev;
            Node* next = node->next;

            prev->next = next;
            next->prev = prev;
        };
        void insert(Node* node){
            Node* rightPrev = right.prev;
            right.prev = node;
            node->next = &right;
            node->prev = rightPrev;
            rightPrev->next = node;
        };
    public:
        LRUCache(int capacity): cap(capacity), left(0, 0), right(0, 0) {
            left.next = &right;
            right.prev = &left;
        }
        
        int get(int key) {
            if(mp.count(key)){
                remove(mp[key]);
                insert(mp[key]);

                return mp[key]->val;
            }
            return -1;
        }
        
        void put(int key, int value) {
            if(mp.count(key)){
                Node* node = mp[key];
                node->val = value;
                remove(node);
                insert(node);
                return;
            }
            mp[key] = new Node(key, value);
            insert(mp[key]);
            if(cap < mp.size()){
                Node* lru = left.next;
                remove(lru);
                mp.erase(lru->key);
                delete lru;
            }
        }
    };
