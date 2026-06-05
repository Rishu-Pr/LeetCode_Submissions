class Solution {
    int solve(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp){
        if(amount == 0) return 0;
        if(amount < 0 || idx == coins.size()) return 1e7;
        if(dp[idx][amount] != -1) return dp[idx][amount];

        int select = 1 + solve(coins, amount - coins[idx], idx,dp);
        int skip = 0 + solve(coins, amount, idx + 1, dp);

        return dp[idx][amount] = min(select, skip);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        int ans = solve(coins, amount, 0, dp);

        return (ans >= 1e7) ? -1 : ans;
    }
};