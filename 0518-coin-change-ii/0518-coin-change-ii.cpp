class Solution {
    int solve(vector<int>& coins, int amount, int idx, vector<vector<int>>& dp){
        
        if(dp[amount][idx] != -1){
            return dp[amount][idx];
        }

        if(amount == 0){
            return 1;
        }
        if(amount < 0 || idx >= coins.size()){
            return 0;
        }

        int ans = 0;

        for(int i = idx; i < coins.size(); i++){
            if(coins[i] <= amount){
                ans += solve(coins, amount - coins[i], i, dp);
            }
        }

        return dp[amount][idx] = ans;
    }
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(5001, vector<int>(3001, -1));
        return solve(coins, amount, 0, dp);
    }
};