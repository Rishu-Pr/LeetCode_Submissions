class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));

        for(int i = m - 1; i >= 0; i--){
            if(obstacleGrid[i][n - 1] == 1) break;
            dp[i][n - 1] = 1;
        }
        for(int i = n - 1; i >= 0; i--){
            if(obstacleGrid[m - 1][i] == 1) break;
            dp[m - 1][i] = 1;
        }

        for(int x = m - 2; x >= 0; x--){
            for(int y = n - 2; y >= 0; y--){
                long long bottom = (obstacleGrid[x + 1][y] == 1) ? 0 : dp[x + 1][y]; 
                long long right = (obstacleGrid[x][y + 1] == 1) ? 0 : dp[x][y + 1];

                dp[x][y] = (obstacleGrid[x][y] == 1) ? 0 : right + bottom; 
            }
        }

        return (int)dp[0][0];
    }
};