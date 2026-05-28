class Solution {
    int solve(int m, int n, int x, int y, vector<vector<int>>& dp){
        if(x == m - 1 && y == n - 1) return 1;
        if(dp[x][y] != -1) return dp[x][y];

        int right = 0;
        int down = 0;
        int ans = 0;

        if(x < m) right = solve(m, n, x + 1, y, dp);
        if(y < n) down = solve(m, n, x, y + 1, dp);
        ans = right + down;

        return dp[x][y] = ans;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int ans = solve(m, n, 0, 0, dp);
        return ans;
    }
};