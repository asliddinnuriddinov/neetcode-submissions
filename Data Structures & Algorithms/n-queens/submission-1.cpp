class Solution {
public:
    unordered_set<int> cols {};
    unordered_set<int> positive {};
    unordered_set<int> negative {};

    vector<vector<string>> ans {};
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        
        dfs(n, board, 0);

        return ans;
    }

    void dfs(int n, vector<string>& board, int r){
        if(r == n){
            ans.push_back(board);
            return;
        }
        for(int c = 0; c < n; c++){
            if(cols.count(c) || positive.count(r + c) || negative.count(r - c)){
                continue;
            }

            cols.insert(c);
            positive.insert(r + c);
            negative.insert(r - c);
            board[r][c] = 'Q';

            dfs(n, board, r + 1);

            cols.erase(c);
            positive.erase(r + c);
            negative.erase(r - c);
            board[r][c] = '.';
        }
    }
};
