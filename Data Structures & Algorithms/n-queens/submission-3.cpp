class Solution {
public:
    vector<vector<string>> res {};
    unordered_set<int> cols {};
    unordered_set<int> pos {};
    unordered_set<int> neg {};
    vector<vector<string>> solveNQueens(int n) {
        vector<string> sub (n, string(n, '.'));
        dfs(n, sub, 0);
        return res;
    }
    void dfs(int &n, vector<string> &sub, int r){
        if(n == r){
            res.push_back(sub);
            return;
        }

        for(int c = 0; c < n; c++){
            if(cols.count(c) || pos.count(c + r) || neg.count(r - c)) continue;
            cols.insert(c);
            pos.insert(c + r);
            neg.insert(r - c);
            sub[r][c] = 'Q';
            dfs(n, sub, r + 1);
            sub[r][c] = '.';
            cols.erase(c);
            pos.erase(c + r);
            neg.erase(r - c);
        }
    }
};
