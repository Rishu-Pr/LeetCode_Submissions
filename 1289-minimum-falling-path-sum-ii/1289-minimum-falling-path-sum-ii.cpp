class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp = grid;

        for(int i = 1; i < m; i++){
            for(int j = 0; j < n; j++){
                int minVal = 1e7;

                for(int k = 0; k < n; k++){
                    if(j != k) minVal = min(minVal, dp[i - 1][k]);
                }
                dp[i][j] += minVal;
            }
        }
        int minV = 1e7;
        for(int i = 0; i < n; i++) minV = min(minV, dp[m - 1][i]);

        return minV;
    }
};