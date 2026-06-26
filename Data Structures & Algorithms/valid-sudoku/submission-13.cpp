class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> cols[9] {};
        unordered_set<char> rows[9] {};
        unordered_set<char> boxes[9] {};

        for(int r = 0; r < board.size(); r++){
            for(int c = 0; c < board[r].size(); c++){
                char &curr = board[r][c];
                if(curr == '.') continue;

                int boxPos = floor(r / 3) * 3 + floor(c / 3);
                if(cols[c].count(curr) || rows[r].count(curr) || boxes[boxPos].count(curr)) return false;

                cols[c].insert(curr);
                rows[r].insert(curr);
                boxes[boxPos].insert(curr);
            }
        }
        return true;
    }
};
