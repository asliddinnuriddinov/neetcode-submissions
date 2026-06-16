class Solution {
public:
    int rows, cols, ans = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        rows = grid.size() - 1, cols = grid[0].size() - 1;

        for(int r = 0; r <= rows; r++){
            for(int c = 0; c <= cols; c++){
                if(grid[r][c] == 1){
                    dfs(grid, r, c);
                }
            }
        }
        return ans;
    }

    int dfs(vector<vector<int>>& grid, int r, int c){
        if(r < 0 || r > rows || c < 0 || c > cols || grid[r][c] == 0) return 0;
        
        grid[r][c] = 0; 
        int sum = 1 + dfs(grid, r + 1, c) + dfs(grid, r - 1, c) + dfs(grid, r, c + 1) + dfs(grid, r, c - 1);
        ans = max(ans, sum);

        return sum;
    }
};
