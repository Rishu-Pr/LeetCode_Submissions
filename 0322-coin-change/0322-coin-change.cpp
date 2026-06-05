class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, 1e9));
        
        for(int j = 0; j <= coins.size(); j++){
            dp[0][j] = 0;
        }
        for(int i = 1; i <= amount; i++){
            for(int j = coins.size() - 1; j >= 0; j--){
                int select = 1e9;
                if(i - coins[j] >= 0) 
                    {select = 1 + dp[i - coins[j]][j];
                }
                int skip = 0 + dp[i][j + 1];
                dp[i][j] = min(skip, select);
            }
        }

        return (dp[amount][0] >= 1e9) ? -1 : dp[amount][0];
    }
};