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
    Node* root = new Node();
public:
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
        return dfs(word, root, 0);
    }

    bool dfs(string& word, Node* root, int i){
        for(int j = i; j < word.length(); j++){
            char &ch = word[j];
            if(ch == '.'){
                for(Node* child : root->children){
                    if(child != NULL && dfs(word, child, j + 1)) return true;
                }
                return false;
            }
            else{
                int ind = ch - 'a';
                if(root->children[ind] == NULL) return false;
                root = root->children[ind];
            }
        }
        return root->endOfWord;
    }
};
