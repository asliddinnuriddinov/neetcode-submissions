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

    void insert(string word){
        TrieNode* curr = this;
        for(char &ch : word){
            int i = ch - 'a';
            if(curr->children[i] == NULL){
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }
};

class Solution {
private:
    void buildTrie(vector<string>& words){
        for(string &word : words){
            root->insert(word);
        }
    }
public:
    int ROWS, COLS;
    TrieNode* root = new TrieNode();
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTrie(words);
        string word = "";
        ROWS = board.size() - 1, COLS = board[0].size() - 1;

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[r].size(); c++){
                dfs(r, c, board, word, root);
            }
        }

        return ans;
    }

    void dfs(int r, int c, vector<vector<char>>& board, string word, TrieNode* curr){
        if(r < 0 || r > ROWS || c < 0 || c > COLS || board[r][c] == '#' || 
            curr->children[board[r][c] - 'a'] == NULL){
            return;
        }

        char ch = board[r][c];
        board[r][c] = '#';
        TrieNode* node = curr->children[ch - 'a'];
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
