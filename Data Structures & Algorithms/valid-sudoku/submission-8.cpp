class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, set<char>> rows {};
        unordered_map<int, set<char>> cols {};
        unordered_map<string, set<char>> boxes {};

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[i].size(); j++){
                char curr = board[i][j];
                if(curr == '.') continue;
                if(cols[j].contains(curr)) return false;
                if(rows[i].contains(curr)) return false;
                cols[j].insert(curr);
                rows[i].insert(curr);

                string boxInd = to_string(floor(i / 3)) + to_string(floor(j / 3));

                if(boxes[boxInd].contains(curr)) return false;
                boxes[boxInd].insert(curr);
            }
        }
        return true;
    }
};