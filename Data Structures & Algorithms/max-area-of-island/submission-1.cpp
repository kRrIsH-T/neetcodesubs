class Solution {
   public:
    int dfs(vector<vector<int>>& grid, int r, int c, vector<vector<bool>>& vis) {
        if (r >= grid.size() || r > vis.size() || r < 0) return 0;
        if (c >= grid[0].size() || c > vis[0].size() || c < 0)return 0;
        if (vis[r][c] || grid[r][c] == 0) return 0;
        else {
            vis[r][c] = true;
            return 1 + dfs(grid,r+1,c,vis) + dfs(grid, r-1,c,vis) + dfs(grid,r,c+1,vis) + dfs(grid,r,c-1,vis);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int max = dfs(grid,i,j,vis);
                if (max > ans) ans = max;
            }
        }
        return ans;
    };
};
