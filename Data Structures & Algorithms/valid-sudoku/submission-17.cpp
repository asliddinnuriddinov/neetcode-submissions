class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9] {};
        unordered_set<char> cols[9] {};
        unordered_set<char> boxes[9] {};

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[r].size(); c++){
                if(board[r][c] == '.') continue;
                char &curr = board[r][c];
                int boxPos = (r / 3) * 3 + (c / 3);

                if(rows[r].count(curr) || cols[c].count(curr) || boxes[boxPos].count(curr)){
                    return false;
                }

                rows[r].insert(curr);
                cols[c].insert(curr);
                boxes[boxPos].insert(curr);
            }
        }
        return true;
    }
};
