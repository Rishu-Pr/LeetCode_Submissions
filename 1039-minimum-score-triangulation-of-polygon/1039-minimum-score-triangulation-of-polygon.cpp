class Solution {
public:
    int solve(vector<int>& values, int i, int j, vector<vector<int>>& dp){
        if(i + 1 == j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = INT_MAX;
        for(int k = i + 1; k < j; k++){
            int val = values[i] * values[j] * values[k];
            ans = min(ans, val + solve(values, i, k, dp) + solve(values, k, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }

    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size(), vector<int>(values.size(), -1));
        int ans = solve(values, 0, values.size() - 1, dp);
        return ans;
    }
};