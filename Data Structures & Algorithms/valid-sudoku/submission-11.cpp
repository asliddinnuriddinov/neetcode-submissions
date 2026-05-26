class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> cols[9];
        unordered_set<char> rows[9];
        unordered_set<char> box[9];

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[r].size(); c++){
                if(board[r][c] == '.') continue;
                int boxPos = floor(r / 3) * 3 + floor(c / 3);

                if(cols[c].contains(board[r][c]) || rows[r].contains(board[r][c]) || box[boxPos].contains(board[r][c])){
                    return false;
                }

                cols[c].insert(board[r][c]);
                rows[r].insert(board[r][c]);
                box[boxPos].insert(board[r][c]);
            }
        }

        return true;
    }
};
