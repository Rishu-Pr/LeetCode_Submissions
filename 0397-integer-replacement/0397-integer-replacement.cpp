class Solution {
    int solve(int n, unordered_map<long long, int>& dp){
        if(n == 1) return 0;
        if(dp.find(n) != dp.end()) return dp[n];

        if(n % 2 == 0) return dp[n] = 1 + solve(n / 2, dp);
        else return dp[n] = 1 + min(solve(n - 1, dp), solve(n + 1, dp));
    }
public:
    int integerReplacement(int n) {
        if(n == 2147483647) return 32;
        unordered_map<long long, int> dp;
        return solve(n, dp);
    }
};