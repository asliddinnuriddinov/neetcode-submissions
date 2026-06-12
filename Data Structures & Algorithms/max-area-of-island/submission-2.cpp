class Solution {
public:
    int ROWS, COLS, ans = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ROWS = grid.size() - 1, COLS = grid[0].size() - 1;

        for(int r = 0; r <= ROWS; r++){
            for(int c = 0; c <= COLS; c++){
                if(grid[r][c] == 1){
                    dfs(grid, r, c);
                }
            }
        }
        
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r > ROWS || c < 0 || c > COLS || grid[r][c] == 0) return 0;

        grid[r][c] = 0;
        int sum = 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c - 1) + dfs(grid, r, c + 1);

        ans = max(ans, sum);
        return sum;
    }
};
