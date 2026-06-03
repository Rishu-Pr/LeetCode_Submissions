class Solution {
    // int solve(vector<int>& prices, int idx, bool isSelected, vector<vector<int>>& dp){
    //     if(idx < 0 && !isSelected) return 0;
    //     if(idx < 0 && isSelected) return -1000000;
    //     if(dp[idx][isSelected] != -1000000) return dp[idx][isSelected];

    //     int profit = 0;
    //     int skip = solve(prices, idx - 1, isSelected, dp);

    //     if(isSelected) profit = solve(prices, idx - 1, false, dp) - prices[idx];
    //     else profit = solve(prices, idx - 1, true, dp) + prices[idx];

    //     return dp[idx][isSelected] = max(profit, skip);
    // }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        dp[1][1] = -prices[0];
        dp[1][0] = 0;

        for(int idx = 2; idx <= prices.size(); idx++){
            dp[idx][0] = max(dp[idx - 1][0], dp[idx - 1][1] + prices[idx - 1]);
            dp[idx][1] = max(dp[idx - 1][1], dp[idx - 1][0] - prices[idx - 1]);
        }
        return dp[prices.size()][0];
    }
};