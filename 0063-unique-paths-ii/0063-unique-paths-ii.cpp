class Solution {
    int solve(vector<vector<int>>& obstacleGrid, int m, int n, int x, int y, vector<vector<int>>& dp){
        if(x >= m || y >= n) return 0;
        if(obstacleGrid[x][y] == 1) return 0;
        if(x == m - 1 && y == n - 1) return 1;
        if(dp[x][y] != -1) return dp[x][y];

        int right = 0;
        int down = 0;

        if(x < m - 1) right = solve(obstacleGrid, m, n, x + 1, y, dp);
        if(y < n - 1) down = solve(obstacleGrid, m, n, x, y + 1, dp);

        return dp[x][y] = right + down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int ans = solve(obstacleGrid, m, n, 0, 0, dp);
        return ans;
    }
};