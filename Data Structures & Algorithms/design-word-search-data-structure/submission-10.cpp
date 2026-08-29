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
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int i, Node* root){
        for(int j = i; j < word.length(); j++){
            char curr = word[j];
            if(curr == '.'){
                for(Node* child : root->children){
                    if(child != NULL && dfs(word, j + 1, child)) return true;
                }
                return false;
            }
            else{
                int ind = curr - 'a';
                if(root->children[ind] == NULL) return false;
                root = root->children[ind];
            }
        }
        return root->endOfWord;
    }
};
