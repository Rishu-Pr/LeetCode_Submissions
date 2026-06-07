class Solution {
    int solve(vector<vector<int>>& grid, int y, int prev_idx, vector<vector<int>>& dp){
        if(y == grid.size()) return 0;
        if(dp[y][prev_idx] != -100) return dp[y][prev_idx];

        int val = 1e7;
        for(int i = 0; i < grid[0].size(); i++){
            if(i != prev_idx) val = min(val, grid[y][i] + solve(grid, y + 1, i, dp));
        }

        return dp[y][prev_idx] = val;
    }
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size() + 1, vector<int>(grid.size() + 1, -100));
        return solve(grid, 0, grid[0].size(), dp);
    }
};