class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;
    TrieNode() {
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
        for(char &ch : word){
            int i = ch - 'a';
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

    bool dfs(string &word, int i, TrieNode* root){
        for(int j = i; j < word.length(); j++){
            char &ch = word[j];
            if(ch == '.'){
                for(TrieNode* child : root->children){
                    if(child != NULL && dfs(word, j + 1, child)) return true;
                }
                return false;
            }
            else{
                int pos = ch - 'a';
                if(root->children[pos] == NULL) return false;
                root = root->children[pos];
            }
        }
        return root->endOfWord;
    }
};
