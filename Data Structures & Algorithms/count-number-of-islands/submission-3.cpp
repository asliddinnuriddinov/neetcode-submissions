class Solution {
public:
    int ROWS, COLS;
    int numIslands(vector<vector<char>>& grid) {
        ROWS = grid.size() - 1, COLS = grid[0].size() - 1;
        int ans = 0;
        for(int r = 0; r <= ROWS; r++){
            for(int c = 0; c <= COLS; c++){
                if(grid[r][c] == '1'){
                    ans++;
                    dfs(grid, r, c);
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || r > ROWS || c < 0 || c > COLS || grid[r][c] == '0') return;

        grid[r][c] = '0';
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
};
