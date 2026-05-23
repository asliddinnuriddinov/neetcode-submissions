class TrieNode {
public:
    TrieNode* children[26] = {};
    bool endOfWord;

    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        endOfWord = false;
    }
};

class WordDictionary {
    TrieNode* root;
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(char c : word){
            int i = c - 'a';
            if(curr->children[i] == NULL){
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string &word, int j, TrieNode* curr){
        for(int i = j; i < word.length(); i++) {
            char c = word[i];
            if(c == '.') {
                for(TrieNode* child : curr->children){
                    if(child == 0) continue;
                    if(child != NULL && dfs(word, i + 1, child)){
                        return true;
                    }
                }
                return false;
            }
            else{
                int pos = c - 'a';
                if(curr->children[pos] == NULL){
                    return false;
                }
                curr = curr->children[pos];
            }
        }
        return curr->endOfWord;
    }
};
