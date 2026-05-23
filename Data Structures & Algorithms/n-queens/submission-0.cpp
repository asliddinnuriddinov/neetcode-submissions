class Solution {
public:
    vector<vector<string>> ans;
    unordered_set<int> col {};
    unordered_set<int> posDiag {};
    unordered_set<int> negDiag {};

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        
        dfs(n, board, 0);

        return ans;
    }

    void dfs(int n, vector<string> &board, int r){
        if(r == n){
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++){
            if(col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) continue;

            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            dfs(n, board, r + 1);

            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';

        }
    }
};
