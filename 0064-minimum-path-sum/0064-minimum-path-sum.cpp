class Solution {
    int solve(vector<vector<int>>& grid, int x, int y, vector<vector<int>>& dp){
        if(x >= grid.size() || y >= grid[0].size()) return 1e9;
        if(x == grid.size() - 1 && y == grid[0].size() - 1) return grid[x][y];
        if(dp[x][y] != -1) return dp[x][y];

        int right = grid[x][y] + solve(grid, x + 1, y, dp);
        int down = grid[x][y] + solve(grid, x, y + 1, dp);
        return dp[x][y] = min(right, down);
    }
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        int ans = solve(grid, 0, 0, dp);
        return ans;
    }
};