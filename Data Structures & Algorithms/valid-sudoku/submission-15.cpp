class Solution {
public:
    unordered_set<char> rows[9];
    unordered_set<char> cols[9];
    unordered_set<char> boxes[9];

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                char &curr = board[r][c];
                if(curr == '.') continue;
                int boxPos = floor(r / 3) * 3 + floor(c / 3);

                if(rows[r].count(curr) || cols[c].count(curr) || boxes[boxPos].count(curr)) return false;

                rows[r].insert(curr);
                cols[c].insert(curr);
                boxes[boxPos].insert(curr);
            }
        }

        return true;
    }
};
