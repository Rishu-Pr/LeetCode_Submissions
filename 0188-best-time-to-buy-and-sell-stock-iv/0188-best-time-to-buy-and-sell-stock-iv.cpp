class Solution {
    int solve(int k, vector<int>& prices, int idx, bool isSell, vector<vector<vector<int>>>& dp){
        if((k == 0 || idx < 0) && isSell == true) return 0;
        if(idx < 0 && isSell == false) return -1e7;
        if(dp[idx][k][isSell] != -1) return dp[idx][k][isSell];

        int sum = 0;
        int next = 0;
        if(isSell == true) sum = solve(k, prices, idx - 1, false, dp) + prices[idx];
        if(isSell == false) sum = solve(k - 1,prices, idx - 1, true, dp) - prices[idx];
        next = solve(k, prices, idx - 1, isSell, dp);

        return dp[idx][k][isSell] = max(sum, next);
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return solve(k, prices, prices.size() - 1, true, dp);
    }
};