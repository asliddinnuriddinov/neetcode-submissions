#include <iostream>
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> rows = {};
        unordered_map<int, unordered_set<char>> columns = {};
        unordered_map<string, unordered_set<char>> box = {};

        for(int i = 0; i < board.size(); i++){
            int rowGrid = floor(i / 3);
            for(int j = 0; j < board[i].size(); j++){
                int colGrid = floor(j / 3);
                if(board[i][j] == '.') continue;
                if( rows[i].contains(board[i][j]) ) return false;
                else rows[i].insert(board[i][j]);

                if( columns[j].contains(board[i][j]) ) return false;
                else columns[j].insert(board[i][j]);

                string boxKey = to_string(rowGrid) + to_string(colGrid);
                if( box[boxKey].contains(board[i][j]) ) return false;
                else box[boxKey].insert(board[i][j]);
            }
        }
        return true;
    }
};
