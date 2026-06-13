#define MOD 1000000007
class Solution {
    int solve(int target, vector<vector<int>>& types, int idx, int sum, vector<vector<int>>& dp){
        if(sum > target) return 0;
        if(idx == types.size()){
            if(sum == target) return 1;
            return 0;
        }
        if(dp[idx][sum] != -1) return dp[idx][sum];
        int ans = 0;
        for(int i = 0; i <= types[idx][0]; i++){
            ans = (ans + solve(target, types, idx + 1, sum + types[idx][1] * i, dp)) % MOD;
        }

        return dp[idx][sum] = ans;
    }
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<vector<int>> dp(types.size() + 1, vector<int>(2 * target, -1));
        return solve(target, types, 0, 0, dp);
    }
};