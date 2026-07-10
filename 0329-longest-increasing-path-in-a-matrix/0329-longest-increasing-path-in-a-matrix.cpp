class Solution {
    int solve(vector<vector<int>>& matrix, int idx_X, int idx_Y, vector<vector<int>>& dp){
        int len = 0;
        if(dp[idx_X][idx_Y] != -1){
            return dp[idx_X][idx_Y];
        }

        int left = 0, right = 0, up = 0, down = 0;
        if(idx_X > 0 && matrix[idx_X - 1][idx_Y] > matrix[idx_X][idx_Y]){
            left = 1 + solve(matrix, idx_X - 1, idx_Y, dp);
        }
        if(idx_X < matrix.size() - 1 && matrix[idx_X + 1][idx_Y] > matrix[idx_X][idx_Y]){
            right = 1 + solve(matrix, idx_X + 1, idx_Y, dp);
        }
        if(idx_Y > 0 && matrix[idx_X][idx_Y - 1] > matrix[idx_X][idx_Y]){
            up = 1 + solve(matrix, idx_X, idx_Y - 1, dp);
        }
        if(idx_Y < matrix[0].size() - 1 && matrix[idx_X][idx_Y + 1] > matrix[idx_X][idx_Y]){
            down = 1 + solve(matrix, idx_X, idx_Y + 1, dp);
        }

        return dp[idx_X][idx_Y] = max(max(left, right), max(up, down));
    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                ans = max(ans, 1 + solve(matrix, i, j, dp));
            }
        }

        return ans;
    }
};