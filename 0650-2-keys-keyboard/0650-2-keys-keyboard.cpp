class Solution {
    int solve(int& n, int curV, int curC, vector<vector<int>>& dp){
        if(curV == n){
            return 0;
        }
        if(curV > n || curC > n){
            return 2001;
        }
        if(dp[curV][curC] != -1){
            return dp[curV][curC];
        }

        int ans = 2001;
        if(curC > 0){
            ans = 1 + solve(n, curV + curC, curC, dp); // paste
        }
        if(curC != curV){
            ans = min(ans, 1 + solve(n, curV, curV, dp)); // copy
        }
        return dp[curV][curC] = ans;
    }
public:
    int minSteps(int n) {
        vector<vector<int>> dp(1001, vector<int>(1001, -1));
        return solve(n, 1, 0, dp);
    }
};