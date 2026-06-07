#define MOD 1000000007
class Solution {
    long long solve(int steps, int arrLen, int idx, vector<vector<int>>& dp){
        if(idx == 0 && steps == 0) return 1;
        if(steps == 0) return 0;
        if(dp[steps][idx] != -1) return dp[steps][idx];

        long long move_left = 0;
        if(idx > 0) move_left = solve(steps - 1, arrLen, idx - 1, dp) % MOD;
        
        long long move_right = 0;
        if(idx < arrLen - 1) move_right = solve(steps - 1, arrLen, idx + 1, dp) % MOD;
        
        long long move_skip = solve(steps - 1, arrLen, idx, dp) % MOD;

        return dp[steps][idx] = (move_left + move_right + move_skip) % MOD;
    }
public:
    int numWays(int steps, int arrLen) {
        int max_reached_len = min(arrLen, steps + 1);
        
        vector<vector<int>> dp(steps + 1, vector<int>(max_reached_len, -1));
        return solve(steps, arrLen, 0, dp) % MOD;
    }
};