class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows = grid.size() - 1, cols = grid[0].size() - 1;
        queue<pair<int, int>> qu {};

        for(int r = 0; r <= rows; r++){
            for(int c = 0; c <= cols; c++){
                if(grid[r][c] == 0){
                    qu.push({r, c});
                }
            }
        }
        vector<pair<int, int>> dirs = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };
        while(!qu.empty()){
            auto [cr, cc] = qu.front();
            qu.pop();

            for(auto [dr, dc] : dirs){
                int nr = dr + cr;
                int nc = dc + cc;
                if(nr < 0 || nr > rows || nc < 0 || nc > cols || grid[nr][nc] != INT_MAX) continue;

                grid[nr][nc] = grid[cr][cc] + 1;
                qu.push({nr, nc});
            }
        }
    }
};
