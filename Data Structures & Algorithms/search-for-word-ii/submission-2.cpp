class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(){
        for(int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        endOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }
    void insert(string word){
        TrieNode* curr = root;
        for(char c : word){
            int pos = c - 'a';
            if(curr->children[pos] == NULL){
                curr->children[pos] = new TrieNode();
            }
            curr = curr->children[pos];
        }
        curr->endOfWord = true;
    }
};

class Solution {
    Trie* trie = new Trie();
    int ROWS, COLS;
private:
    void buildTrie(vector<string>& words){
        for(string word : words){
            trie->insert(word);
        }
    }
public:
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTrie(words);
        TrieNode* root = trie->root;
        ROWS = board.size() - 1, COLS = board[0].size() - 1;
        string word = "";
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[r].size(); c++){
                dfs(r, c, board, word, root);
            }
        }

        return ans;
    }

    void dfs(int r, int c, vector<vector<char>>& board, string &word, TrieNode* root){
        if(r < 0 || c < 0 || r > ROWS || c > COLS || board[r][c] == '#' || 
            root->children[board[r][c] - 'a'] == NULL){
            return;
        }

        char ch = board[r][c];
        board[r][c] = '#';
        TrieNode* node = root->children[ch - 'a'];
        word.push_back(ch);
        if(node->endOfWord){
            ans.push_back(word);
            node->endOfWord = false;
        }

        dfs(r + 1, c, board, word, node);
        dfs(r - 1, c, board, word, node);
        dfs(r, c + 1, board, word, node);
        dfs(r, c - 1, board, word, node);

        board[r][c] = ch;
        word.pop_back();
    }
};
