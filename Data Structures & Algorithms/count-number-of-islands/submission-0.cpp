class Solution {
public:
    unordered_set<string> seen {};
    int ROWS, COLS;
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        ROWS = grid.size() - 1, COLS = grid[0].size() - 1;
        for(int r = 0; r <= ROWS; r++){
            for(int c = 0; c <= COLS; c++){
                if(!seen.contains(to_string(r) + to_string(c)) && grid[r][c] == '1'){
                    result+=1;
                    dfs(grid, r, c);
                }
            }
        }
        return result;
    }

    void dfs(vector<vector<char>>& grid, int r, int c){
        if(seen.contains(to_string(r) + to_string(c)) || r < 0 || r > ROWS || c < 0 || c > COLS || grid[r][c] == '0') return;

        seen.insert(to_string(r) + to_string(c));

        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }
};
