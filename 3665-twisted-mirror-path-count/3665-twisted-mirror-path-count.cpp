class Solution {
    int MOD = 1e9 + 7;

    int solve(vector<vector<int>>& grid, int x, int y, int dir, vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (x >= m || y >= n){
            return 0;
        }
        if (x == m - 1 && y == n - 1){
            return 1;
        }
        if (dp[y][x][dir] != -1){
            return dp[y][x][dir];
        }
        
        long long ans = 0;
        
        if (grid[y][x] == 1) {
            if (dir == 0) { 
                ans = (ans + solve(grid, x, y + 1, 1, dp)) % MOD;
            }
            else { 
                ans = (ans + solve(grid, x + 1, y, 0, dp)) % MOD;
            }
        }
        else {
            ans = (ans + solve(grid, x + 1, y, 0, dp)) % MOD;
            ans = (ans + solve(grid, x, y + 1, 1, dp)) % MOD;
        }
        
        return dp[y][x][dir] = ans;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (n == 1 && m == 1) return 1;
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
        
        long long ans = 0;
        
        ans = (ans + solve(grid, 1, 0, 0, dp)) % MOD;
        ans = (ans + solve(grid, 0, 1, 1, dp)) % MOD;
        
        return ans;
    }
};