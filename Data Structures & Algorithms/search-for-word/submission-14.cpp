class Solution {
public:
    int ROWS, COLS;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size(), COLS = board[0].size();

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(board[r][c] == word[0] && dfs(board, r, c, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int r, int c, string& word, int i){
        if(i == word.size()) return true;
        if(r < 0 || c < 0 || r >= ROWS || c >= COLS || board[r][c] != word[i]){
            return false;
        }
        char curr = board[r][c];
        board[r][c] = '#';
        bool res = dfs(board, r + 1, c, word, i + 1) ||
                   dfs(board, r - 1, c, word, i + 1) ||
                   dfs(board, r, c + 1, word, i + 1) ||
                   dfs(board, r, c - 1, word, i + 1);
        board[r][c] = curr;
        return res;
    }
};
