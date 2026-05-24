class Solution {
public:
    int ROWS, COLS;
    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size() - 1, COLS = board[0].size() - 1;

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[r].size(); c++){
                if(word[0] == board[r][c] && dfs(board, word, r, c, 0)){
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(vector<vector<char>>& board, string &word, int r, int c, int i){
        if(i == word.length()) return true;

        if(r < 0 || c < 0 || r > ROWS || c > COLS || board[r][c] == '#' || board[r][c] != word[i]){
            return false;
        }

        board[r][c] = '#';

        bool res = dfs(board, word, r + 1, c, i + 1) ||
                   dfs(board, word, r - 1, c, i + 1) ||
                   dfs(board, word, r, c + 1, i + 1) ||
                   dfs(board, word, r, c - 1, i + 1);

        board[r][c] = word[i];

        return res;
    }
};
