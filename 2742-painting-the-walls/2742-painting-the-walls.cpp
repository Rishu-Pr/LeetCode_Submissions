class Solution {
    vector<vector<int>> dp;
    int n;
    int solve(vector<int>& cost, vector<int>& time, int idx, int remain){
        if (remain <= 0) return 0; 
        if (idx == n) return 1e9; 

        if (dp[idx][remain] != -1) return dp[idx][remain];

        int paint = cost[idx] + solve(cost, time, idx + 1, remain - 1 - time[idx]);

        int skip = solve(cost, time, idx + 1, remain);

        return dp[idx][remain] = min(paint, skip);
    }
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        dp = vector<vector<int>>(n, vector<int>(n + 1, -1));

        return solve(cost, time, 0, n);
    }
};