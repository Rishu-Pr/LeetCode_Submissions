class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1) return 1;

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m - 2][n - 1] = 1;
        dp[m - 1][n - 2] = 1;
        for(int i = 0; i < m - 1; i++) dp[i][n - 1] = 1;
        for(int i = 0; i < n - 1; i++) dp[m - 1][i] = 1;

        for(int x = m - 2; x >= 0; x--){
            for(int y = n - 2; y >= 0; y--){
                dp[x][y] = dp[x][y + 1] + dp[x + 1][y];
            }
        }

        return dp[0][0];
    }
};