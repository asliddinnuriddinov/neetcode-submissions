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

    void add(string word){
        TrieNode* curr = this;
        for(char &c : word){
            int i = c - 'a';
            if(curr->children[i] == NULL){
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i]; 
        }
        curr->endOfWord = true;
    }
};

class Solution {
    TrieNode* root = new TrieNode();
    int ROWS, COLS;
private:
    void buildTrie(vector<string>& words){
        for(string word : words){
            root->add(word);
        }
    }
public:
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTrie(words);
        ROWS = board.size() - 1, COLS = board[0].size() - 1;
        string word = "";
        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[r].size(); c++){
                dfs(r, c, board, word, root);
            }
        }

        return ans;
    }

    void dfs(int r, int c, vector<vector<char>>& board, string &word, TrieNode* curr){
        if(r < 0 || c < 0 || r > ROWS || c > COLS || board[r][c] == '#' || 
            curr->children[board[r][c]  - 'a'] == NULL
        ){
            return;
        }

        char ch = board[r][c];
        board[r][c] = '#';
        word.push_back(ch);
        TrieNode* node = curr->children[ch - 'a'];
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
