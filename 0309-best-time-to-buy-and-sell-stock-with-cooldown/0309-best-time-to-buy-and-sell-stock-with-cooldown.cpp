class Solution {
    int solve(vector<int>& prices, int idx, int chc, vector<vector<int>>& dp){
        if(idx >= prices.size()){
            return 0;
        }
        if(dp[idx][chc] != -1){
            return dp[idx][chc];
        }

        int skip = solve(prices, idx + 1, chc, dp);
        int buy = 0;
        int sell = 0;
        if(!chc){
            buy = solve(prices, idx + 1, 1, dp) - prices[idx];
        }
        else{
            sell = solve(prices, idx + 2, 0, dp) + prices[idx];
        }

        return dp[idx][chc] = max(skip, max(buy, sell));
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return solve(prices, 0, 0, dp);
    }
};