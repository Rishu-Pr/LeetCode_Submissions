class Solution {
    int solve(vector<int>& prices, int fee, int idx, int buySell, vector<vector<int>>& dp){ // 1 for buy 0 for sell
        if(idx >= prices.size()){
            if(!buySell){
                return -1e6;
            }
            return 0;
        }
        if(dp[idx][buySell] != -1e9){
            return dp[idx][buySell];
        }
        
        int ans = -1e7;
        if(buySell){
            ans = solve(prices, fee, idx + 1, 0, dp) - prices[idx];
        }
        else{
            ans = solve(prices, fee, idx + 1, 1, dp) + prices[idx] - fee;
        }

        ans = max(ans, solve(prices, fee, idx + 1, buySell, dp));

        return dp[idx][buySell] = ans;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1e9));
        return solve(prices, fee, 0, 1, dp);
    }
};