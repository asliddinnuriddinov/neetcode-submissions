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

    void add(string &word){
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
            root->add(word);
        }
    }
public:
    TrieNode* root = new TrieNode();
    int ROWS, COLS;
    vector<string> ans {};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        buildTrie(words);
        ROWS = board.size() - 1, COLS = board[0].size() - 1;
        string word = "";
        for(int r = 0; r <= ROWS; r++){
            for(int c = 0; c <= COLS; c++){
                dfs(r, c, board, root, word);
            }
        }

        return ans;
    }

    void dfs(int r, int c, vector<vector<char>>& board, TrieNode* curr, string& word){
        if(r < 0 || r > ROWS || c < 0 || c > COLS || board[r][c] == '#'
            || curr->children[board[r][c] - 'a'] == NULL) return;

        char ch = board[r][c];
        TrieNode* node = curr->children[ch - 'a'];
        board[r][c] = '#';
        word.push_back(ch);
        if(node->endOfWord){
            ans.push_back(word);
            node->endOfWord = false;
        }

        dfs(r + 1, c, board, node, word);
        dfs(r - 1, c, board, node, word);
        dfs(r, c + 1, board, node, word);
        dfs(r, c - 1, board, node, word);

        board[r][c] = ch;
        word.pop_back();
    }
};
