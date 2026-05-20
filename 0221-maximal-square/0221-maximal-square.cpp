class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));

        int maxVal = 0;
        for(int i = row - 1; i >= 0; i-- ){
            for(int j = col - 1; j >= 0; j--){        
                int right = dp[i][j + 1];
                int diag = dp[i + 1][j + 1];
                int bottom = dp[i + 1][j];

                if(matrix[i][j] == '1'){
                    dp[i][j] = 1 + min(right, min(diag, bottom));
                    maxVal = max(dp[i][j], maxVal);
                }
                else dp[i][j] = 0;
            }
        }

        return maxVal * maxVal;
    }
};