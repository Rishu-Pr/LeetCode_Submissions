#define MOD 1000000007
class Solution {
    long long solve(int n, int prev, vector<vector<long long>>& dp){
        if(n == 1) return 1;
        if(dp[n][prev] != -1) return dp[n][prev];

        int Val = 0;
        
        if(prev == 0) Val = solve(n - 1, 1, dp) % MOD;
        if(prev == 1) Val = (solve(n - 1, 0, dp) + solve(n - 1, 2, dp)) % MOD;
        if(prev == 2) Val = (solve(n - 1, 0, dp) + solve(n - 1, 1, dp) + solve(n - 1, 3, dp) + solve(n - 1, 4, dp)) % MOD;
        if(prev == 3) Val = (solve(n - 1, 2, dp) + solve(n - 1, 4, dp)) % MOD;
        if(prev == 4) Val = solve(n - 1, 0, dp) % MOD;

        return dp[n][prev] = Val;
    }
public:
    int countVowelPermutation(int n) {
        vector<vector<long long>> dp(n + 1, vector<long long>(5, -1));
        
        long long ans = 0;
        for(int i = 0; i < 5; i++){        
            ans = (ans + solve(n, i, dp)) % MOD;
        }
        return ans;
    }
};