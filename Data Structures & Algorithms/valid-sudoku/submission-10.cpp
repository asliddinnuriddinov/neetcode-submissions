class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows [9];
        unordered_set<char> cols [9];
        unordered_set<char> boxes [9];

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                char curr = board[i][j];
                if(curr == '.') continue;
                if(cols[j].contains(curr)) return false;
                if(rows[i].contains(curr)) return false;
                cols[j].insert(curr);
                rows[i].insert(curr);

                int boxInd = floor(i / 3) * 3 + floor(j / 3);

                if(boxes[boxInd].contains(curr)) return false;
                boxes[boxInd].insert(curr);
            }
        }
        return true;
    }
};