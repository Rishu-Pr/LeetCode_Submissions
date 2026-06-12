#define MOD 1000000007
class Solution {
    int solve(vector<vector<int>>& grid, int k, int x_Idx, int y_Idx, int current_remainder, vector<vector<vector<int>>>& dp){
        int m = grid.size();
        int n = grid[0].size();

        if(x_Idx >= m || y_Idx >= n) return 0;

        int new_remainder = (current_remainder + grid[x_Idx][y_Idx]) % k;

        if(x_Idx == m - 1 && y_Idx == n - 1){
            return (new_remainder == 0) ? 1 : 0;
        }

        if(dp[x_Idx][y_Idx][current_remainder] != -1) {
            return dp[x_Idx][y_Idx][current_remainder];
        }

        int right = solve(grid, k, x_Idx + 1, y_Idx, new_remainder, dp);
        int down = solve(grid, k, x_Idx, y_Idx + 1, new_remainder, dp);

        return dp[x_Idx][y_Idx][current_remainder] = (down + right) % MOD;
    }
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k, -1)));
        return solve(grid, k, 0, 0, 0, dp);
        
    }
};