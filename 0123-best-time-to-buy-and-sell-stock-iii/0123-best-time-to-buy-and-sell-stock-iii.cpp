class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(3, vector<int>(2, -1e7)));
        for(int k = 0; k <= 2; k++)
            dp[0][k][1] = 0;

        for(int i = 1; i <= n; i++){
            for(int k = 0; k <= 2; k++){
                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k][0] + prices[i - 1]);
                if(k > 0) dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k - 1][1] - prices[i - 1]);
            }
        }

        return max(dp[n][0][1], max(dp[n][1][1], dp[n][2][1]));
    }
};