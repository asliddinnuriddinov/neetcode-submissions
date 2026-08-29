class Node {
public:
    Node* children[26];
    bool endOfWord;
    Node() {
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        endOfWord = false;
    }
};

class PrefixTree {
    Node* root = new Node();
public:
    PrefixTree() {
        
    }
    
    void insert(string word) {
        Node* curr = root;
        for(char &ch : word){
            int ind = ch - 'a';
            if(curr->children[ind] == NULL){
                curr->children[ind] = new Node();
            }
            curr = curr->children[ind];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        Node* curr = root;
        for(char &ch : word){
            int ind = ch - 'a';
            if(curr->children[ind] == NULL) return false;
            curr = curr->children[ind];
        }
        return curr->endOfWord;
    }
    
    bool startsWith(string prefix) {
        Node* curr = root;
        for(char &ch : prefix){
            int ind = ch - 'a';
            if(curr->children[ind] == NULL) return false;
            curr = curr->children[ind];
        }
        return true;
    }
};
