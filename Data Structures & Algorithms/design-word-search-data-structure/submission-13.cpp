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

class WordDictionary {
public:
    Node* root = new Node();
    WordDictionary() {
        
    }
    
    void addWord(string word) {
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
        return dfsSearch(root, word, 0);
    }
private:
    bool dfsSearch(Node* curr, string& word, int i){
        for(int j = i; j < word.length(); j++){
            char &ch = word[j];
            if(ch == '.'){
                for(Node* child : curr->children){
                    if(child && dfsSearch(child, word, j + 1)) return true;
                }
                return false;
            }
            else{
                int ind = ch - 'a';
                if(curr->children[ind] == NULL) return false;
                curr = curr->children[ind];
            }
        }
        return curr->endOfWord;
    }
};
