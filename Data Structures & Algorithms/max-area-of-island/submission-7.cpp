class Solution {
   public:
    int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r >= grid.size() || r < 0) return 0;
        if (c >= grid[0].size() || c < 0)return 0;
        if (grid[r][c] == 0) return 0;
        else {
            grid[r][c] = 0;
            return 1 + dfs(grid,r+1,c) + dfs(grid, r-1,c) + dfs(grid,r,c+1) + dfs(grid,r,c-1);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(grid[i][j] ==1)ans = max(ans,dfs(grid,i,j));
            }
        }
        return ans;
    };
};
