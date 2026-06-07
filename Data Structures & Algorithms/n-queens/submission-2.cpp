class Solution {
public:
    vector<vector<string>> ans {};
    unordered_set<int> cols {};
    unordered_set<int> pos {};
    unordered_set<int> neg {};

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        dfs(n, board, 0);

        return ans;
    }

    void dfs(int n, vector<string>& board, int r){
        if(r == n){
            ans.push_back(board);
        }

        for(int c = 0; c < n; c++){
            if(cols.count(c) || pos.count(r + c) || neg.count(r - c)) continue;
            cols.insert(c);
            pos.insert(r + c);
            neg.insert(r - c);
            board[r][c] = 'Q';
            dfs(n, board, r + 1);
            cols.erase(c);
            pos.erase(r + c);
            neg.erase(r - c);
            board[r][c] = '.';
        }
    }
};
