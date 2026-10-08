class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n + 2, 1);
        for(int i = 0; i < nums.size(); i++){
            ans[i + 1] = nums[i];
        }
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for(int i = n; i >= 1; i--){
            for(int j = i; j <= n; j++){
                int maxV = 0;
                for(int k = i; k <= j; k++){
                    maxV = max(ans[i - 1] * ans[k] * ans[j + 1] + dp[i][k - 1] + dp[k + 1][j], maxV);
                }
                dp[i][j] = maxV;
            }
        }

        return dp[1][n];
    }
};