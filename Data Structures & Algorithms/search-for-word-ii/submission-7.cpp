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
    void insert(string word){
        Node* curr = this;
        for(char &ch : word){
            int ind = ch - 'a';
            if(curr->children[ind] == NULL){
                curr->children[ind] = new Node();
            }
            curr = curr->children[ind];
        }
        curr->endOfWord = true;
    }
};

class Solution {
private:
    void build(vector<string>& words){
        for(string &word : words){
            trie->insert(word);
        }
    }
public:
    Node* trie = new Node();
    int ROWS, COLS;
    vector<string> res {};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        build(words);
        ROWS = board.size(), COLS = board[0].size();
        string word = "";
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                dfs(r, c, board, word, trie);
            }
        }
        return res;
    }

    void dfs(int r, int c, vector<vector<char>>& board, string& word, Node* trie){
        if(r >= ROWS || c >= COLS || r < 0 || c < 0 || board[r][c] == '#' || trie->children[board[r][c] - 'a'] == NULL) return;

        char ch = board[r][c];
        Node* node = trie->children[ch - 'a'];
        word.push_back(ch);
        if(node->endOfWord){
            res.push_back(word);
            node->endOfWord = false;
        }
        board[r][c] = '#';
        dfs(r + 1, c, board, word, node);
        dfs(r - 1, c, board, word, node);
        dfs(r, c + 1, board, word, node);
        dfs(r, c - 1, board, word, node);
        board[r][c] = ch;
        word.pop_back();
    }
};
