class Solution {
    int solve(int n, vector<int>& dp){
        if(n < 2) return 1;
        if(dp[n] != -1) return dp[n];
        
        int prd = 1;
        for(int i = 1; i <= n; i++){
            prd = max(prd, i * solve(n - i, dp));
        }

        return dp[n] = prd;
    }
public:
    int integerBreak(int n) {
        if(n == 2) return 1;
        if(n == 3) return 2;

        vector<int> dp(n + 1, -1);
        
        return solve(n, dp);
    }
};